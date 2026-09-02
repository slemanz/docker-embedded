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
