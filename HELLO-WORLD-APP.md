# Hello World Qt 6 Application

A sample of a Qt 6 application to demonstrate the use of the Torizon ecosystem.

## Prerequisites

This sample use the Torizon VS Code Extension v2. Follow the [Torizon VS Code Extension v2 (ApolloX)](https://github.com/toradex/torizon-experimental-torizon-ide-v2-docs) instructions to install the prerequisites and register the target device on the development PC.

#### Opening the Project

With the Torizon VS Code Extension v2 installed and the target device connected, clone the project repository in your development PC:

```bash
git clone https://github.com/toradex/torizon-rpi-x86-docs
```

> ⚠️ Be sure to update the permissions of the insecure shared keys used for debug connections:
```bash
cd torizon-rpi-x86-docs
cd helloWorld
chmod 600 .conf/id_rsa
```

Open the `helloWorld` folder on VS Code:

```bash
cd torizon-rpi-x86-docs
cd helloWorld
code .
```

##### Check Project Dependencies

When opening the project folder in VS Code the extension will ask if it can run a dependency check, click `Yes`:

![](https://docs.toradex.com/111530-vscodecheckdeps.png)

A new VS Code terminal will be opened to run the dependency check. If there are dependencies that must be installed, confirm the installation by typing `y` and `Enter` at the terminal prompt:

![](https://docs.toradex.com/111531-checkdepsfailed.png)

> ⚠️ Your administrator password will be requested during the installation of the packages, pay attention to the terminal prompt.

##### Remote Deploy & Remote Debug

- Click on `Run and Debug` on the VS Code activity bar;

- Select the Torizon architecture of you development board target;
  
  - For this sample only `Torizon ARMv8` (Raspberry Pi) and `Torizon x86` (Torizon x86-64);

- Click on `Start debugging` or press `F5` to start debugging;

![](https://docs.toradex.com/111532-startdebuggingqt6.gif)

> ⚠️ This task has several automated steps, your application will be compiled for the selected architecture, a new docker image will be built, delivered to the target (the default device registered), the image will be initialized on the target and then connected to the VS Code debugger. The first time it runs it may take a while, wait until the end.

> ⚠️ Once the user selects the Torizon architecture in the `Run and Debug` combo box, VS Code will use this same option for the next sessions, not having to select it again. So, the user can start a new debug session just by pressing `F5` key.

If at the end the tasks ran without exceptions you will be able to see a Qt 6 application running on your device, which consists of a white background with the Torizon logo in the center.

![](https://docs.toradex.com/111538-qt6torizonapp.png)

# Next Steps - Torizon Over the Air Updates

To familiarize yourself with the Torizon ecosystem, follow the instructions for using the Torizon Platform Services (free tier) to deploy and update this application over the air:

[Torizon Over the Air Updates](OTA.md)
