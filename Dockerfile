FROM ubuntu:22.04 AS build
LABEL Description="Build environment"
RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    ninja-build \
    libgl1-mesa-dev \
    libvulkan-dev \
    libxkbcommon-dev \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-l10n-tools
WORKDIR /usr/app
COPY . /usr/app
#ENV DCMAKE_PREFIX_PATH /usr/lib/qt6
RUN mkdir -p build
#RUN rm -f CMakeLists.txt.user
RUN cmake -S . \
    -B ./build -G Ninja
RUN ninja -C ./build

# run the app
FROM ubuntu:22.04
COPY --from=build /usr/app/build/qt-hello /usr/bin
RUN apt-get update && apt-get -y --no-install-recommends install \
    libqt6core6 \
    libqt6gui6 \ 
    libqt6widgets6 \
    qt6-wayland
#    weston?
ENV QT_QPA_PLATFORM=wayland
ENV QT_PLUGIN_PATH=/usr/lib/x86_64-linux-gnu/qt6/plugins
ENV QT_QPA_PLATFORM_PLUGIN_PATH=/usr/lib/x86_64-linux-gnu/qt6/plugins/platforms
ENV LD_LIBRARY_PATH=/usr/lib/x86_64-linux-gnu
ENV QT_DEBUG_PLUGINS=1
#WORKDIR /usr/bin
EXPOSE 3000
ENTRYPOINT [ "/usr/bin/qt-hello" ]
