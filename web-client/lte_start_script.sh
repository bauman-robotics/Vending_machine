sleep 20
echo "AT+CRESET;\r" >/dev/ttyUSB3
sleep 30
/usr/bin/qmicli -d /dev/cdc-wdm0 --dms-set-operating-mode='online'
sleep 3
/usr/bin/qmicli -d /dev/cdc-wdm0 --dms-get-operating-mode
/usr/bin/qmicli -d /dev/cdc-wdm0 --nas-get-signal-strength
/usr/bin/qmicli -d /dev/cdc-wdm0 --nas-get-home-network
ip link set wwan0 down
sleep 1
echo 'Y' | tee /sys/class/net/wwan0/qmi/raw_ip
sleep 1
ip link set wwan0 up
sleep 5
/usr/bin/qmicli -p -d /dev/cdc-wdm0 --device-open-net='net-raw-ip|net-no-qos-header' --wds-start-network="apn='internet',username='megafon',password='megafon',ip-type=4" --client-no-release-cid
sleep 5
/usr/sbin/udhcpc -i wwan0
