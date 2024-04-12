#!/bin/bash

truncate -s 0 temp_files/system_sfml_controller.txt
cd temp_files
truncate -s 0 current_song.txt
truncate -s 0 next_song.txt
truncate -s 0 previous_songs.txt
truncate -s 0 next_songs.txt
truncate -s 0 remote.txt

