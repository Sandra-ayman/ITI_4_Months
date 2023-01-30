from PIL import Image
from time import sleep
import ST7735 as TFT
import Adafruit_GPIO as GPIO
import Adafruit_GPIO.SPI as SPI
WIDTH = 128
HEIGHT = 160
SPEED_HZ = 4000000
# Raspberry Pi configuration.
DC = 24
RST = 25
SPI_PORT = 0
SPI_DEVICE = 0
# Create TFT LCD display class.
disp = TFT.ST7735(
    DC,
    rst=RST,
    spi=SPI.SpiDev(
        SPI_PORT,
        SPI_DEVICE,
        max_speed_hz=SPEED_HZ))
# Initialize display.
disp.begin()
# Load an image.
print('Loading image...')
image1 = Image.open('Winnie-The-Pooh.jpg')
image2 = Image.open('winnie_and_fegla.jpg')
image3 = Image.open('TOM_&_JERRY.jpg')
image4 = Image.open('Mickey-Mouswe-MAIN-FI.jpg')
# Resize the image and rotate it so matches the display.
image1 = image1.resize((WIDTH, HEIGHT))
image2 = image2.resize((WIDTH, HEIGHT))
image3 = image3.resize((WIDTH, HEIGHT))
image4 = image4.resize((WIDTH, HEIGHT))
# Draw the image on the display hardware.
print('Drawing image')
disp.display(image1)
sleep(1)
disp.display(image2)
sleep(1)
disp.display(image3)
sleep(1)
disp.display(image4)