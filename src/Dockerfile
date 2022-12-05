FROM ubuntu:22.04 AS build
LABEL Description="Build environment"
RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    ninja \
    libgl1-mesa-dev \
    libvulkan-dev \
    libxkbcommon-dev \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-l10n-tools
WORKDIR /usr/src/app
COPY . /usr/src/app
#ENV DCMAKE_PREFIX_PATH /usr/lib/qt6
RUN cmake .. -G Ninja && ninja

# run the app
FROM gcr.io/distroless/nodejs:18
COPY --from=build /usr/src/monorepo/common/deploy /usr/src/app
RUN apt-get update && apt-get -y --no-install-recommends install \
    qt6-base-dev
#    qt6-wayland? weston?

WORKDIR /usr/src/app
EXPOSE 3000
ENTRYPOINT [ "build/qt-hello" ]
