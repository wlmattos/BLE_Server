# invoke SourceDir generated makefile for app_ble.pem3
app_ble.pem3: .libraries,app_ble.pem3
.libraries,app_ble.pem3: package/cfg/app_ble_pem3.xdl
	$(MAKE) -f C:\ti\ble_examples-simplelink_sdk-1.35\examples\rtos\CC2640R2_LAUNCHXL\ble5apps\spp_ble_server\tirtos\ccs\config/src/makefile.libs

clean::
	$(MAKE) -f C:\ti\ble_examples-simplelink_sdk-1.35\examples\rtos\CC2640R2_LAUNCHXL\ble5apps\spp_ble_server\tirtos\ccs\config/src/makefile.libs clean

