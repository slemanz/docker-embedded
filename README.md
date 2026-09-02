# Docker Embedded

Command reference:

## The three words

- **Image:** a frozen filesystem. Your toolchain: gcc, make, libraries. Built
once, never changes. Like an ISO file.

- **Container:** a running instance of an image. Starts, runs one command,
exits, and you throw it away. Like booting that ISO in a VM you delete after.

- **Bind mount:** a directory on your machine, lent to a container while it
runs. The container sees it, edits it, and the changes are on your disk because
it *is* your disk.

Note that your source code does not go inside the image. You do not clone your
repo into the image. The image is the compiler, your repo is the input. You
mount the repo into a throwaway container, run `make`, and the .elf appears in
your local folder.

## Run a container, delete it

The lifecycles of a container, follows:

```bash
docker run --rm -it ubuntu:24.04 bash
```

- run = create a container from an image and start it
- --rm = delete the container when the command exits
- -it = interactive + terminal (needed for a shell)
- ubuntu:24.04 = the image
- bash = the command to run inside

After this, you will be in the root of a fresh Ubuntu. Try:

```bash
cd home
touch iwashere
ls
arm-none-eabi-gcc --version    # command not found (plain ubuntu has no toolchain)
exit
```

Run the exact same command again and look for "iwashere". It is gone. The
containeir was destroyed; the image never changed. **Containers are disposable,
images are not.**