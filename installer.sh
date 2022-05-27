echo 'please make sure your wingsxi'
echo 'zip file is in the Downloads/leetxi'
echo 'directory of your user'
echo 'make this directory if needed'
echo 'press enter to continue...'
read trash

7z x ~/Downloads/leetxi/*.7z

WINEPREFIX=/opt/ffxi wine ~/Downloads/leetxi/Installer\ Package/Installer.exe

echo 'running a short cleanup'

cp /opt/ffxi/drive_c/WingsXI/Ashita/config/boot/New\ Configuration\ 1.xml /opt/ffxi/drive_c/WingsXI/Ashita/config/boot/wings.xml
rm /opt/ffxi/drive_c/WingsXI/Ashita/config/boot/New\ Configuration\ 1.xml

echo 'please be sure to run configure ashita'
echo 'upon first launch of leetxi'
echo 'let it update, and then close'
echo 'using the launch command'
echo 'as ashita gui has issues'
echo 'in wine'
