# Torizon for Raspberry Pi and x86-64

Torizon is a software platform that simplifies the process of developing and maintaining embedded software. It allows you to configure the system for IoT/IIoT with over the air updates (OTA) quickly and easily, so you can focus on application development instead of Linux builds. With Torizon Pi, for Raspberry Pi and x86 boards, we are extending the support of the platform and its ecosystem beyond Toradex hardware.

## Getting Started

### Torizon for Raspberry Pi

Supported hardware:

- Raspberry Pi 3B

- Raspberry Pi 3B+

- Raspberry Pi 4B

#### Flashing SD Card

The easiest way to flash an SD Card to be ready with TorizonCore for Raspberry Pi is using the [Raspberry PI Imager](https://downloads.raspberrypi.org/imager/).

Download and install Raspberry Pi Imager:

- [Raspberry Pi Imager for Debian/Ubuntu](https://downloads.raspberrypi.org/imager/imager_latest_amd64.deb)

- [Raspberry Pi Imager for Windows](https://downloads.raspberrypi.org/imager/imager_latest.exe)

Open a new terminal and execute Raspberry Pi Imager using the Toradex images repo:

```bash
rpi-imager --repo https://docs.toradex.com/111488-os_list_imagingutility.json
```

In the Raspberry Pi Imager follow the steps:

- Click on `CHOOSE OS` and select the TorizonCore installation related to your hardware;

- Click on `CHOOSE STORAGE` and select the device related to the SD Card target;

- Click on `WRITE` to flash;

> ⚠️ Before flashing the storage selected, the Raspberry Pi Imager will ask for your confirmation and administrator password. Be sure to select the right media, this operation will erase previous data from the storage selected and there is no going back.

![](https://docs.toradex.com/111523-flashingraspberrypi.gif)

##### First Boot

The board terminal can be accessed by the following methods:

- Using an USB keyboard connect to the board;

- Using a serial to USB converter:
  
  <img title="" src="https://docs.toradex.com/111524-raspberrypiserialtousb.png?w=400" alt="" data-align="left">

- With an Ethernet cable connected, using `SSH` (you can use IP address or hostname):

![](https://docs.toradex.com/111525-raspberrypifirstboot.gif)

> ⚠️ The hostname follows the pattern `raspberrypi<model version>-64-<board serial number>`. Example:
> 
> ```bash
> raspberrypi3-64-00000000f01c7e18
> ```
> 
> If you have an HDMI connected to the board you can probably see the hostname written on the screen.

Use the follow credentials to login:

- Login: `torizon`

- Password: `torizon`

> ⚠️ As a security measure TorizonCore uses the default password only for the first login, requiring a password change.

### Torizon for x86-64

#### Flashing Storage

> ⚠️ These are the same instructions for create a live USB drive installation

Download the compressed `WIC` image:

- [Torizon for x86-64](https://share.toradex.com/4p1uu0zemkdwe7f)

Extract the `WIC` file, and flash it. You can use the follow methods:

Using `dd`:

```bash
sudo dd if=torizon-core-docker-intel-corei7-64.wic of=/dev/storage-device bs=4M
```

Using `bmap-tools`:

```bash
sudo bmaptool copy --nobmap torizon-core-docker-intel-corei7-64.wic /dev/storage-device
```

Using [Balena Etcher](https://github.com/balena-io/etcher/releases):

> ⚠️ If you prefer a graphical user interface option, Balena Etcher supports flashing WIC images

- Click on `Flash from file` and select the `torizon-core-docker-intel-corei7-64.wic` file location;

- Click on `Select target` and select the storage device to flash the image;

- Click on `Flash!` to write the flash to the storage selected;

![](https://docs.toradex.com/111526-torizonx86flashing.gif)

> ⚠️ Before flashing the storage selected, the Balena Etcher will ask for your confirmation and administrator password. Be sure to select the right media, this operation will erase previous data from the storage selected and there is no going back.

#### Virtual Machine

Download the compressed `VMDK` image:

- [Torizon for x86-64 Virtual Machine Image](https://share.toradex.com/2d9bko5vc2m6gmp)

##### Running Using QEMU

> ⚠️ TorizonCore x86-64 needs UEFI to boot. Install the `ovmf` package to have the bios files.

```bash
qemu-system-x86_64 \
    -smp 2 \
    -device AC97 \
    -device virtio-vga \
    -enable-kvm \
    -m 1024 \
    -bios /usr/share/ovmf/OVMF.fd \
    -hda "torizon-core-docker-intel-corei7-64.wic.vmdk" \
    -net user \
    -name "torizon"
```

##### Running on Virtual Box

- Click on `New`;

- Input the new VM name;

- Select a folder to be created for store the new configuration VM files;

- Select `Linux` on type combo box;

- Select `Other Linux (64-bit)` on Version combo box;

- Click `Next`;

- Set `1024` for the memory size;

- Click `Next`;

- Select `Use a existing virtual file disk`;

- Click in the folder icon;

- Click on `Add`;

- Choose the location for the `torizon-core-docker-intel-corei7-64.wic.vmdk` file and click on `Open`;

- Click `Choose`;

- Click `Create`;

![](https://docs.toradex.com/111528-creatingnewvboxvm.gif)

> ⚠️ TorizonCore x86-64 needs UEFI to boot. So, make sure to select the EFI option on the VM settings.

- With the new VM created selected, click on `Settings`;

- Select `System` and click for tick the `Enable EFI (special OSes only)` option;

- **Optional:** Select `Display` and click for tick the `Enable 3D Acceleration`;

![](https://docs.toradex.com/111529-vboxfinalconfiguration.gif)

#### First Boot

The board terminal can be accessed by the following methods:

- Using an USB keyboard connect to the board;

- With an Ethernet cable connected, using `SSH` (you can use IP address or hostname):

![](https://docs.toradex.com/111527-x86firstboot.gif)

> ⚠️ The hostname for TorizonCore for x86 is  `torizon-x86`

Use the follow credentials to login:

- Login: `torizon`

- Password: `torizon`

> ⚠️ As a security measure TorizonCore uses the default password only for the first login, requiring a password change.

### Hello World Application

## Building Torizon for Raspberry Pi and x86-64 using Yocto
