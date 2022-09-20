# Build Instructions for TorizonCore Labs

Torizon is a software platform that simplifies the process of developing and maintaining embedded software. It allows you to configure the system for IoT/IIoT with over the air updates (OTA) quickly and easily, so you can focus on application development instead of Linux builds. With Torizon for Raspberry Pi and x86-64 devices, we experiment with extending the Torizon ecosystem beyond Toradex SoMs.

> ⚠️ **This software is provided experimentally as-is. Users may self-onboard, self-support and/or work with an integration partner to evaluate Torizon for Raspberry Pi & x86-64, RISC-V, systems. Please share with us your feedback & any interest to use Torizon in your product.**



## Building Using TorizonCore Build Environment

The TorizonCore Build Environment is a project that extends CROPS to build a TorizonCore image. CROPS is a Docker image for building Yocto based distros which is maintained by the Yocto Project.

### Prerequisites[​](https://developer.toradex.com/torizon/in-depth/build-torizoncore-from-source-with-yocto-projectopenembedded/#prerequisites-1 "Direct link to heading")

The following prerequisites are mandatory:

- Linux (or Windows WSL 2) host with [Docker](https://www.docker.com/) installed;
- GIT;
- [Repo](https://source.android.com/docs/setup/download#installing-repo);

### Getting the Source Code

All the layers needed to build TorizonCore are describe on the Toradex Labs manifest repository:

```bash
git clone https://github.com/microhobby/toradex-manifest
```

Create a Torizon work directory to be used:

```bash
mkdir workdir
cd workdir
mkdir torizon
cd torizon
```

Init the repo in the `workdir/torizon` folder using `toradex-manifest` information:

```bash
repo init -u ../../toradex-manifest -b labs -m torizoncore/labs.xml
repo sync
```

Run the TorizonCore Build Environment docker container:

```bash
docker run --rm -it --name=crops7 -v /home/<your-user>/workdir:/workdir --workdir=/workdir -e MACHINE=<your-machine> -e IMAGE=torizon-core-docker torizon/crops:kirkstone-6.x.y startup-tdx.sh
```

> ⚠️ Remember to change the `<your-user>` with your Linux user (or the path where your create the `workdir` folder).
> 
> ⚠️ Remember to change the `<your-machine>` with the respective machine from target hardware that you want to build.

| Target Hardware  | MACHINE            |
| ---------------- |:------------------ |
| Raspberry Pi 4B  | raspberrypi4-64    |
| Raspberry Pi 3B  | raspberrypi3-64    |
| Raspberry Pi 3B+ | raspberrypi3-64    |
| Intel x86-64     | intel-corei7-64    |
| AMD x86-64       | intel-corei7-64    |
| Nezha D1         | nezha-allwinner-d1 |

At the end of the build if everything went as expected you should have the artifacts in:

```bash
workdir/torizon/build-torizon-upstream/deploy/images/<your-machine>/
```


