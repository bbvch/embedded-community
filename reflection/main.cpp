#include <print>
#include <nlohmann/json.hpp>
#include <meta>
#include <vector>
#include <optional>

struct Student {
    Student(std::initializer_list<float> grades_) : grades{grades_} {}
    std::vector<float> grades;
private:
    int secret{42};
};

struct User {
    std::string name;
    int age;
    std::optional<Student> student;
};

template<typename T>
concept is_assignable_value = std::is_constructible_v<nlohmann::json, T>;

template<is_assignable_value T>
nlohmann::json to_json(const T& data) {
    return data;
}

template<typename T>
nlohmann::json to_json(const T& data) {
    nlohmann::json ret_obj = nlohmann::json::value_t::object;
    constexpr auto refl_obj = ^^T;
    constexpr auto static refl_members = std::define_static_array(std::meta::nonstatic_data_members_of(refl_obj, std::meta::access_context::unchecked()));
    template for (constexpr auto refl_member : refl_members) {
        ret_obj[std::meta::identifier_of(refl_member)] = to_json(data.[:refl_member:]);
    }
    return ret_obj;
}

template<typename T>
nlohmann::json to_json(const std::optional<T>& data) {
    return data.has_value() ? to_json(*data) : nlohmann::json(nullptr);
}

int main() {
    User user1{"User1", 55};
    std::println("User1: {}", to_json(user1).dump(2));
    User user2{"User2", 19, Student{{5.0, 4.5}}};
    std::println("User2: {}", to_json(user2).dump(2));
}
