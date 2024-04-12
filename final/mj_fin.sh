#!/bin/bash

#rm -f /home/blake/Desktop/testing/temp_files/*.txt
rm -f /home/blake/Desktop/final/album_covers/*.JPEG
# cd temp_files
# > current_sleep.txt
# > current_song.txt
# > previous_song.txt
# > next_song.txt

./clearFiles.sh

# Need to run the script to get the hardware id of the pi
cd /home/blake/Desktop/final/python_scripts
python3 hardware_id.py

cd /home/blake/Desktop/final/python_scripts


# Runs all the controller polling
# Polls website for controls 
python3 poll_website.py&
# Polls buttons for controls (GPIO)
python3 buttons.py&

# Function to run sfml script
run_cpp_program() {
    cd /home/blake/Desktop/final/sfml_programs
    g++ -c main2_v3.cpp
    g++ main2_v3.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
    ./sfml-app
}


# Cleanup to kill the different programs running
cleanup()
{
    echo "caught ctrl+c, cleaning up"
    exit 0
}



# Run welcome screen
cd /home/blake/Desktop/final/sfml_programs
g++ -c welcomeScreen.cpp
g++ welcomeScreen.o -o sfml-welcome -lsfml-graphics -lsfml-window -lsfml-system
./sfml-welcome

cd /home/blake/Desktop/final/
./clearFiles.sh

# Run queue handling (so that the first song is always in there when started)
cd /home/blake/Desktop/final/python_scripts
python3 main.py  &

# Sleep to handle queue from the start
# sleep 15

run_cpp_program &


cd ../
# Poll cec-client for remote 
# cec-client | ./cecremote.sh&

trap cleanup SIGINT
