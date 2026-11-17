FROM gcc:16.2.0

RUN apt-get update \
    && apt-get install -y --no-install-recommends cmake ninja-build gdb git nlohmann-json3-dev vim \
    && rm -rf /var/lib/apt/lists/* \
    && useradd --create-home --shell /bin/bash vscode

USER vscode
