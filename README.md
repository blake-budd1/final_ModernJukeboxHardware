<h2>The Modern Jukebox Hardware</h2>

<h4>Download instructions </h4>
<p>In order to install The Modern Jukebox hardware section, download the .tar.gz file. 
Once downloaded, unzip the file on the Raspberry Pi. Then run the install.sh script using './install.sh'.
This will install all dependencies needed to successfully run the package. </p>

<p> In order to link it to your Spotify account, you first need to go to spotify developer (https://developer.spotify.com/) and create a new app.</p>
<p> Once the app is created, then navigate to settings, and note the client ID and client secret. These need to be added to the text file in the unzipped file structure. </p>
<p> Additionally, once the install script has been ran and the client ID and client secret have been updated. Take a device on the same WIFI network and navigate to the spotify app. From here, change the playback device to 'Raspberrypi (Raspodify)'. 
    Then, navigate to the following page on the Spotify Developer website to get the device id. https://developer.spotify.com/documentation/web-api/reference/get-a-users-available-devices</p>
    <p>Do the option to try on the right side of the screen and you will see the following device named Raspberrypi. Get the device ID and update it in the same file as the Client ID and Client secret.</p>

<p> Once this is done, the user can then use the main bash script to start the program and will not have to interact with it at all afterwards. </p>
<h5>To run the program, use the following command in the command line on the raspberry pi: ./modern_jukebox.sh</h5>

<h4> How the program works </h4>
<p> The program is to be used with a front-end website: https://the-modern-jukebox-react-app.vercel.app/</p>
<p> The user will be able to add songs, join sessions, and create new sessions using that website.</p>
<p> The hardware section is to be plugged into speakers and a display (using an HDMI connection) to allow the user to display the queue and use either the buttons, remote, or website to control the playback and handle skipping, pausing, playing, or going to the previous song</p>
