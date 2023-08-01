# Imports PIL module
import PIL

# creating a image object (new image object) with
# RGB mode and size 200x200
im = PIL.Image.new(mode="RGB", size=(200, 200))

# This method will show image in any image viewer
im.show()
