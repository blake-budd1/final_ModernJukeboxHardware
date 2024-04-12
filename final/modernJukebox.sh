#!/bin/bash

rm -f /album_covers/*.JPEG

./clearFiles.sh

# Need to run the script to get the hardware id of the pi
cd /python_scripts
python3 hardware_id.py




# Runs all the controller polling
# Polls website for controls 
python3 poll_website.py&
# Polls buttons for controls (GPIO)
python3 buttons.py&

# Function to run sfml script
run_cpp_program() {
    cd /sfml_programs
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
cd ..
cd /sfml_programs
g++ -c welcomeScreen.cpp
g++ welcomeScreen.o -o sfml-welcome -lsfml-graphics -lsfml-window -lsfml-system
./sfml-welcome

cd ..
./clearFiles.sh


# Run queue handling (so that the first song is always in there when started)
cd /python_scripts
python3 main.py  &

# Sleep to handle queue from the start
# sleep 15
cd ..
run_cpp_program &


cd ../
# Poll cec-client for remote 
# cec-client | ./cecremote.sh&

trap cleanup SIGINT
