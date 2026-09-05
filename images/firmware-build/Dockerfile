FROM ubuntu:24.04

# Install necessary packages
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    make \
    vim \
    git \
    python3 \
    ca-certificates \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    && rm -rf /var/lib/apt/lists/*

# The default directory when a container starts.
WORKDIR /work

# Default command when none is given
CMD ["bash"]