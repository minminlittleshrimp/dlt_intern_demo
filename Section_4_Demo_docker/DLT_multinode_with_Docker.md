# Guide for setting up Multinode Demo with Docker Setup

# Multinode Background

## 1. Problem Statement

Multiple dlt-daemons are running on different Operating Systems. Developers want to analyze them as one system.

## 1.2. Multinode Overview

The central component is the Gateway DLT Daemon which connects external DLT Clients, like the DLT Viewer running on a host computer with Passive DLT Daemons running on nodes without a physical connection to external DLT clients. All communication between passive nodes and DLT Viewer has to be sent via the Gateway node. The Gateway node forwards log messages coming from passive nodes to all connected DLT clients.

# Docker setup to create container run as passive node

## 2.1. Stop the Docker Daemon (if it's running):

```bash
sudo systemctl stop docker
```

## 2.2. Edit the Docker Configuration File:

Open the Docker daemon configuration file in a text editor:

```bash
sudo nano /etc/docker/daemon.json
```

If the `daemon.json` file doesn't exist, you can create it. Here's an example `daemon.json` file that configures Docker to use a specific subnet:

```json
{
    "bip": "192.168.2.1/24"
}
```

In this example, `bip` specifies the subnet and subnet mask. Replace `"192.168.2.1/24"` with the desired subnet and subnet mask for your environment.

## 2.3. Save the Configuration File and Exit the Text Editor:

For `nano`, press `Ctrl + O`, then Enter to save, and `Ctrl + X` to exit.

## 2.4. Restart the Docker Daemon:

```bash
sudo systemctl restart docker
```

## 2.5. Use ifconfig to check docker0 inet. It should be "192.168.2.1" as below:

```
docker0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
            inet 192.168.2.1  netmask 255.255.255.0  broadcast 192.168.2.255
            inet6 fe80::42:10ff:fe7e:67be  prefixlen 64  scopeid 0x20<link>
            ether 02:42:10:7e:67:be  txqueuelen 0  (Ethernet)
            RX packets 542560  bytes 1199069256 (1.1 GB)
            RX errors 0  dropped 0  overruns 0  frame 0
            TX packets 410017  bytes 1197497831 (1.1 GB)
           TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```

## 2.6. Create a container with bridge network with the below example cmd:

```bash
docker run -it --name dlt_bridge1  -v /home/${USER}/work:/home/${USER}/work -w /home/${USER} ubuntu
```

- `-it`: making it possible to interact with the container via the command line.
- `-v`: mount the container from host -> container.
- `-w`: set work dir inside container. When the container starts, the command prompt will be in this directory.

Use cmd "docker network inspect bridge" to get IP of container that created with bridge mode.

```
"Containers": {
    "4e9091956bf9ad920c43afdbf676043b426134dc5ade9f2fba5e978955484e25": {
        "Name": "proxi",
        "EndpointID": "debc04f129aab5829f75b103751a1c97b6cbac03c6d87c29dd19affcf78047ea",
        "MacAddress": "02:42:c0:a8:02:02",
        "IPv4Address": "192.168.2.2/24",
        "IPv6Address": ""
    },
    "8e5f06bbc42de9a5de5597ab1a404c826ab767c82c63b76750a0f044b80a0a03": {
        "Name": "dlt_bridge1",
        "EndpointID": "fbebef0d7f1843d0cb5e933e351cc557a7b3911d43bbcd185ab006ad284d575b",
        "MacAddress": "02:42:c0:a8:02:03",
        "IPv4Address": "192.168.2.3/24",
        "IPv6Address": ""
    }
},
```

## 2.7. Install dlt bin and lib in the container:

```bash
root@2ff461cda2f5:/home/<$USER>/work/docker/dlt-daemon# cp ./build/src/daemon/dlt-daemon /usr/local/bin/
root@2ff461cda2f5:/home/<$USER>/work/docker/dlt-daemon# cp ./build/src/daemon/dlt-example-user /usr/local/bin/
root@2ff461cda2f5:/home/<$USER>/work/docker/dlt-daemon# cp ./build/src/lib/libdlt* /usr/local/lib/
```

## 2.8. Config for gateway and passive node.

### 2.8.1. On Passive node (container):

```bash
dlt-daemon -p 3495 -c dlt.conf
```

dlt.conf: ECUid=DOCK

```bash
dlt-example-user -n 100000 hello
```

### 2.8.2. On DLT Gateway (virtual machine):

Configuration for gateway in case of using host network for container creation:

```
dlt.conf: Gateway = 1, dlt_gateway.conf: IP = 192.168.2.1, Port=3495 ECUid=DOCK
```

Configuration for gateway in case of using bridge network for container creation:

```
dlt.conf: Gateway = 1, dlt_gateway.conf: IP = 192.168.2.3(please use cmd "docker network inspect bridge" to check it), Port=3495 ECUid=DOCK
```

Start dlt-daemon. Start dlt-receive -a localhost to observe whether the dlt client on gateway node are able to receive dlt log from passive node or not.
```

**Note**: The section "Docker start dlt_bridge1" and "Docker exec -It dlt_bridge1 bash" appears to be repeated. I have excluded them assuming they are duplicates. If not, please let me know.