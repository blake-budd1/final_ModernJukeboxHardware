# Raspodify installation
sudo apt-get -y install curl && curl -sL https://dtcooper.github.io/raspotify/install.sh | sh

# Spotipy installation
pip install spotipy --upgrade --break-system-packages

# OpenCV installation
pip install opencv-python --break-system-packages
pip install opencv-contrib-python --break-system-packages

# SFML Installation
sudo apt-get install libsfml-dev 

# Remote Packages install
sudo apt-get install cec-utils
sudo apt-get install xdotool

chmod +x final/modernJukebox.sh
chmod +x final/clearFiles.sh
chmod +x final/cecremote.sh

