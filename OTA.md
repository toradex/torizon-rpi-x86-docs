# Torizon Over the Air Updates

Using the Hello World Qt 6 Application sample, we will introduce how to use Torizon Platform Services to deploy and update containerized application in your device with Torizon Core.

## Create Torizon Platform Services Account

- Access https://app.torizon.io/

- Click on `Create Account`;

- Fill in the required inputs;

- Click on `Create Account`;

- Check your e-mail and follow the instructions to verify your account;

- Sign in with your credentials;

## Provisioning Device

With an account created and logged into Torizon Platform Services, a device can be provisioned to receive remote updates. 

**In the Torizon Platform Services web application:**

- Click in `Devices` on the sidebar;

- Click in `+ PROVISION DEVICE` ;

- Click in the copy icon to copy the provisioning command;

**In the device to be provisioned:**

> ⚠️ In case the device is a Torizon x86-64, before executing the provisioning command, it is necessary to execute:
> 
> ```bash
> docker run --rm -it --privileged torizon/binfmt
> ```

- Access the terminal of the device under provisioning;

- Paste the provisioning command and press `Enter` to run;

- Wait for the end of the command, input the device password to start the update polling service;

![](https://docs.toradex.com/111533-provisioningx86.gif)

**In the Torizon Platform Services web application:**

After running the provisioning command and the update system polling service reaches the Torizon Platform Services a new device (random name) will be presented on your devices.

## Deploying Application

### Creating a Docker Compose Package

**In the VS Code with Hello World Qt 6 Application opened:**

- With the Explorer activity opened click in the `TASK RUNNER`;

- Click in the `create-production-image` command;

- Input your container image registry (your Dockerhub user for example);

- Input a tag for the release (v1 for example);

- Select the target device architecture;

- Input the container image registry password (your Dockerhub user password);

![](https://docs.toradex.com/111534-creatingimageforproduction.gif)

> ⚠️ This task has several automated steps, your application will be compiled for the selected architecture, a new docker image will be built, pushed to the your container image registry. The first time it runs it may take a while, wait until the end.

At the end of the task, after the new image is pushed to the container registry, there will be a new file `docker-compose.prod.yml` in the root of the project folder. This file will be ready for use in Torizon Platform Services.

**In the Torizon Platform Services web application:**

- Click in the `Packages` on the sidebar;

- Click `+ ADD NEW PACKAGE`;

- Click `Docker Compose`;

- Click `ATTACH DOCKER COMPOSE FILE`;

- Select the `docker-compose.prod.yml` file from Hello World Qt 6 Application folder;

- Click `CONTINUE`;

- Input a `Package name`;

- Input a `Version` (v2 for example);

- Click `UPLOAD`;

![](https://docs.toradex.com/111535-creatingpackagev1.gif)

### Over the Air Deploying Docker Compose Package

With a new Docker Compose package created it is finally possible to deploy the application on the target device:

- Click in the `Devices` on the sidebar;

- Click in the previous device provisioned;

- At bottom click in the `Initiate Update`;

- Select the `docker-compose (Application Package)`;

- Click in the `CONTINUE >`;

- Select the previous docker-compose package created in `Select package` combo box;

- Click in the `CONTINUE >`;

- Check the summary from your selections and confirm it clicking in the `FINISH`;

![](https://docs.toradex.com/111536-triggeringupdatev1.gif)

Wait for the update polling window (approximately 5 minutes), for the deployment to occur on the selected provisioned device.

By selecting the provisioned device it is also possible to follow the status of the queued update:

![](https://docs.toradex.com/111537-updatev1success.png)

If everything goes as expected during the update a successful update notification will be shown in the Torizon Platform Services web application. In the device the application will be deployed and you will be able to see a Qt 6 application running in the provisioned device, which consists of a white background with the Torizon logo in the center.

![](https://docs.toradex.com/111538-qt6torizonapp.png)

## Over the Air Updating Docker Compose Package

Once a docker compose package is deployed, if any changes to the application are developed, an update can be triggered.

**In the VS Code with Hello World Qt 6 Application opened:**

- Open the file `QML/main.qml` in the editor;

- Uncomment lines `12` until `29` and save the file;

- With the Explorer activity opened click in the `TASK RUNNER`;

- Click in the `create-production-image` command;

- Input your container image registry (your Dockerhub user for example);

- Input a tag for the new release (v2 for example);

- Select the target device architecture;

- Input the container image registry password (your Dockerhub user password);

![](https://docs.toradex.com/111539-creatingpackagev2.gif)

At the end of the task, after the new image tag is pushed to the container registry, the file `docker-compose.prod.yml` will be overwritten with the new tag. This file will be ready for use in Torizon Platform Services to trigger the update.

**In the Torizon Platform Services web application:**

- Click in the `Packages` on the sidebar;

- Click `+ ADD NEW PACKAGE`;

- Click `Docker Compose`;

- Click `ATTACH DOCKER COMPOSE FILE`;

- Select the `docker-compose.prod.yml` file from Hello World Qt 6 Application folder;

- Click `CONTINUE`;

- Input the `Package name`;
  
  - > ⚠️ Be sure to put the same package name as previously.

- Input a new `Version` (v2 for example);

- Click `UPLOAD`;

![](https://docs.toradex.com/111540-creatingdcv2.gif)

With the Docker Compose package updated it is finally possible to queue the application update on the provisioned device:

- Click in the `Devices` on the sidebar;

- Click in the previous device provisioned;

- At bottom, click in the `Initiate Update`;

- Select the `docker-compose (Application Package)`;

- Click in the `CONTINUE >`;

- Select the previous docker-compose package updated in `Select package` combo box;

- Select the updated version in the `Select version` combo box (v2 for example);

- Click in the `CONTINUE >`;

- Check the summary from your selections and confirm it clicking in the `FINISH`;

![](https://docs.toradex.com/111541-triggerupdatev2.gif)

Wait for the update polling window (approximately 5 minutes), for the deployment to occur on the selected provisioned device.

By selecting the provisioned device it is also possible to follow the status of the queued update:

![](https://docs.toradex.com/111542-updatestatus.gif)

If everything goes as expected during the update a successful update notification will be shown in the Torizon Platform Services web application. 

In the device the application will be deployed and you will be able to see a Qt 6 application running in the provisioned device, which consists of a white background with the Torizon logo showing in a zoom in/fade in animation (the updated animations that are uncommented from the QML file).

https://docs1.toradex.com/111544-20220822_014143.mp4


