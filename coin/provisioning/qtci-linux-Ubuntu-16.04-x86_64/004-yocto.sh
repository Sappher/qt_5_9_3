#!/bin/bash

#############################################################################
##
## Copyright (C) 2017 The Qt Company Ltd.
## Contact: http://www.qt.io/licensing/
##
## This file is part of the provisioning scripts of the Qt Toolkit.
##
## $QT_BEGIN_LICENSE:LGPL21$
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company. For licensing terms
## and conditions see http://www.qt.io/terms-conditions. For further
## information use the contact form at http://www.qt.io/contact-us.
##
## GNU Lesser General Public License Usage
## Alternatively, this file may be used under the terms of the GNU Lesser
## General Public License version 2.1 or version 3 as published by the Free
## Software Foundation and appearing in the file LICENSE.LGPLv21 and
## LICENSE.LGPLv3 included in the packaging of this file. Please review the
## following information to ensure the GNU Lesser General Public License
## requirements will be met: https://www.gnu.org/licenses/lgpl.html and
## http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
##
## As a special exception, The Qt Company gives you certain additional
## rights. These rights are described in The Qt Company LGPL Exception
## version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
##
## $QT_END_LICENSE$
##
#############################################################################

# This script installs the Yocto toolchain

set -e

source "${BASH_SOURCE%/*}/../common/DownloadURL.sh"

echo "Installing Yocto toolchain for 32-bit b2qt..."

versionARM="2.2.2"
package="b2qt-x86_64-meta-toolchain-b2qt-embedded-sdk-qemuarmv7-2c947f7.sh"
PrimaryUrl="http://ci-files01-hki.intra.qt.io/input/boot2qt/morty/$package"
AltUrl="http://download.qt.io/development_releases/prebuilt/boot2qt/morty/$package"
SHA1="2583ae29951954cb27f12400fcb4ee94738d1430"
yoctoInstaller="/tmp/yocto-toolchain-ARMv7.sh"
yoctoLocationARMv7="/opt/yocto-armv7"
sysrootARMv7="sysroots/armv7ahf-neon-poky-linux-gnueabi"
crosscompileARMv7="sysroots/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-"

DownloadURL "$PrimaryUrl" "$AltUrl" "$SHA1" "$yoctoInstaller"
chmod +x "$yoctoInstaller"

/bin/bash "$yoctoInstaller" -y -d "$yoctoLocationARMv7"
rm -rf "$yoctoInstaller"

echo "Installing Yocto toolchain for 64-bit b2qt..."

versionARM64="2.2.2"
package="b2qt-x86_64-meta-toolchain-b2qt-embedded-sdk-qemuarm64-2c947f7.sh"
PrimaryUrl="http://ci-files01-hki.intra.qt.io/input/boot2qt/morty/$package"
AltUrl="http://download.qt.io/development_releases/prebuilt/boot2qt/morty/$package"
SHA1="512b5bc1ad62af88d021eb511eeac4648d661fc6"
yoctoInstaller="/tmp/yocto-toolchain-ARM64.sh"
yoctoLocationARM64="/opt/yocto-arm64"
sysrootARM64="sysroots/aarch64-poky-linux"
crosscompileARM64="sysroots/x86_64-pokysdk-linux/usr/bin/aarch64-poky-linux/aarch64-poky-linux-"

DownloadURL "$PrimaryUrl" "$AltUrl" "$SHA1" "$yoctoInstaller"
chmod +x "$yoctoInstaller"

/bin/bash "$yoctoInstaller" -y -d "$yoctoLocationARM64"
rm -rf "$yoctoInstaller"

if [ -e "$yoctoLocationARMv7/$sysrootARMv7" -a -e "$yoctoLocationARMv7/${crosscompileARMv7}g++" -a -e "$yoctoLocationARM64/$sysrootARM64" -a -e "$yoctoLocationARM64/${crosscompileARM64}g++" ]; then
    echo "export QEMUARMV7_TOOLCHAIN_SYSROOT=$yoctoLocationARMv7/$sysrootARMv7" >> ~/.profile
    echo "export QEMUARMV7_TOOLCHAIN_CROSS_COMPILE=$yoctoLocationARMv7/$crosscompileARMv7" >> ~/.profile
    echo "export QEMUARM64_TOOLCHAIN_SYSROOT=$yoctoLocationARM64/$sysrootARM64" >> ~/.profile
    echo "export QEMUARM64_TOOLCHAIN_CROSS_COMPILE=$yoctoLocationARM64/$crosscompileARM64" >> ~/.profile
else
    echo "Error! Couldn't find installation paths for Yocto toolchain. Aborting provisioning." 1>&2
    exit 1
fi

echo "Yocto ARMv7 toolchain = $versionARM" >> ~/versions.txt
echo "Yocto ARM64 toolchain = $versionARM64" >> ~/versions.txt
