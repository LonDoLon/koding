#!/usr/bin/env bash

# TESTINGEN!!!! REMOVE IF updating works!! NOw put this!!!

if [[ ! "$(uname)" = "Linux" ]]; then
    echo "Currenty only Ubuntu Linux is supported"
    exit 1
fi

CHANNEL="development"
LATESTVERSION=$(curl -s https://s3.amazonaws.com/koding-klient/${CHANNEL}/latest-version.txt)
LATESTURL="https://s3.amazonaws.com/koding-klient/${CHANNEL}/latest/klient_0.1.${LATESTVERSION}_${CHANNEL}_amd64.deb"
KONTROLURL="https://koding.com/kontrol/kite"

echo "Downloading and installing klient 0.1.${LATESTVERSION}"
curl -s $LATESTURL -o klient.deb
sudo dpkg -i --force-confnew klient.deb > /dev/null

echo "Authenticating to ${KONTROLURL}"
sudo -E /opt/kite/klient/klient -register -kite-home "/etc/kite" --kontrol-url "$KONTROLURL"

if [ ! -f /etc/kite/kite.key ]; then
    echo "/etc/kite/kite.key not found. Aborting installation"
    exit -1
fi

# Production kontrol might return a different kontrol URL. Let us control this aspect.
escaped_var=$(printf '%s\n' "$KONTROLURL" | sed 's:[/&\]:\\&:g;s/$/\\/')
sudo sed -i "s/\.\/klient/\.\/klient -kontrol-url $escaped_var -env managed /g" "/etc/init/klient.conf"

# We need to restart it so it pick up the new environment variable
sudo service klient restart

