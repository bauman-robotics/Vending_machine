#echo "AT+CRESET;\r" >/dev/ttyUSB3
#sleep 10
sudo /usr/bin/qmicli -d /dev/cdc-wdm0 --dms-set-operating-mode='online'
sleep 3
sudo /usr/bin/qmicli -d /dev/cdc-wdm0 --dms-set-operating-mode='online'
sleep 3
sudo /usr/bin/qmicli -d /dev/cdc-wdm0 --dms-set-operating-mode='online'
/usr/bin/qmicli -d /dev/cdc-wdm0 --dms-get-operating-mode
/usr/bin/qmicli -d /dev/cdc-wdm0 --nas-get-signal-strength
/usr/bin/qmicli -d /dev/cdc-wdm0 --nas-get-home-network
sudo ip link set wwan0 down
sleep 1
sudo echo 'Y' | tee /sys/class/net/wwan0/qmi/raw_ip
sleep 1
ip link set wwan0 up
sleep 1
sudo /usr/bin/qmicli -p -d /dev/cdc-wdm0 --device-open-net='net-raw-ip|net-no-qos-header' --wds-start-network="apn='internet',username='megafon',password='megafon',ip-type=4" --client-no-release-cid
sleep 1
sudo /usr/sbin/udhcpc -i wwan0
sleep 5
echo "nameserver 8.8.8.8" > /etc/resolv.conf
