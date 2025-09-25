FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
ENV LANG=C.UTF-8 LC_ALL=C.UTF-8
# Evita problemi con Wayland/XWayland
ENV GDK_BACKEND=x11
ENV QT_X11_NO_MITSHM=1

# Abilita 'universe' e installa base + Python/venv + Node + GUI deps
RUN apt-get update && apt-get install -y --no-install-recommends \
    software-properties-common \
 && add-apt-repository -y universe \
 && apt-get update && apt-get install -y --no-install-recommends \
    sudo make git ca-certificates curl \
    python3 python3-pip python3-venv \
    nodejs npm \
    vim autoconf help2man \
    graphviz xdot python3-gi gir1.2-gtk-3.0 \
    dbus-x11 libgl1 mesa-utils \
    fonts-dejavu-core fonts-urw-base35 fonts-liberation \
 && rm -rf /var/lib/apt/lists/*

# Venv
RUN python3 -m venv /opt/venv
ENV VIRTUAL_ENV=/opt/venv
ENV PATH="$VIRTUAL_ENV/bin:$PATH"

# Clona la repo
RUN git clone https://github.com/EneaDim/flexsoc.git /opt/flexsoc
WORKDIR /opt/flexsoc

# make deps (ora NIENTE xvfb)
RUN apt-get update && make deps && rm -rf /var/lib/apt/lists/*

CMD ["/bin/bash"]

