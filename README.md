# How to build (containerize a Qt6 app)

`docker build . -t qt-hello:0.0.4`

# How to run

`docker run --rm -e WAYLAND_DISPLAY=$WAYLAND_DISPLAY -e XDG_RUNTIME_DIR=/tmp -v $XDG_RUNTIME_DIR/$WAYLAND_DISPLAY:/tmp/$WAYLAND_DISPLAY localhost/qt-hello:0.0.4`

If you need to enter the container to view the environments and experiment with it:

```sh
docker run -it --entrypoint /bin/bash
   -e WAYLAND_DISPLAY=$WAYLAND_DISPLAY \
   -e XDG_RUNTIME_DIR=/tmp \
   -v $XDG_RUNTIME_DIR/$WAYLAND_DISPLAY:/tmp/$WAYLAND_DISPLAY \
   localhost/qt-hello:0.0.4
```

# Issues

1. Cannot open a model dialog

>  Wayland does not support QWindow::requestActivate()


