import requests
import json
import time



line = ""
with open("../temp_files/hardware_id.txt", "r") as id_file:
    line = id_file.readlines()
    id_file.close()
session_id = line[0]

print(session_id)


website = "https://the-modern-jukebox-react-app.vercel.app/api/" + session_id + "/controls"

print(website)
previous = "null"

while(1):
    time.sleep(3)
    r = requests.get(website)
    
    if(previous != r.text and r.text != "null"):
        previous = r.text
        # controls = json.loads(r.text)
        controls = r.json()
        if(controls["play"]):
            f = open("../remote.txt", "a")
            f.write("play\n")
            f.close()
        elif(controls["pause"]):
            f = open("../remote.txt", "a")
            f.write("pause\n")
            f.close()
        elif(controls["next"]):
            f = open("../remote.txt", "a")
            f.write("next\n")
            f.close()
        elif(controls["previous"]):
            f = open("../remote.txt", "a")
            f.write("previous\n")
            f.close()
        r = requests.delete(website)