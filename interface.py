#!/usr/bin/python

from tkinter import *
from PIL import Image, ImageDraw
import os

#Window
from window import Window

root = Tk()

root.title("Simple Graph")

root.resizable(0,0)

points = []

hist = []

size = 20,20

tag1 = "theline"

image1 = Image.new("1", (140, 140), "white")
draw = ImageDraw.Draw(image1)


def point(event):
	c.create_oval(event.x, event.y, event.x+1, event.y+1, fill="black")
	points.append(event.x)
	points.append(event.y)

	if len(points) >= 4:
		c.create_line(points, tags="theline")
		draw.line(points, fill=0, width = 7)

	return points

def canxy(event):
	print (event.x, event.y)

def graph(event):
	global theline
	c.create_line(points, tags="theline")
	c.itemconfigure(tag1, smooth=1)
	
	
def stopDraw(event):		#separates lines
	while len(points)>0:
		hist.append(points.pop())

	return points
def clear(event):   
	c.delete("all")
	c.update()
	image1 = Image.new("L", (140, 140), "white")
	draw = ImageDraw.Draw(image1)

def getNumber():
	image1.thumbnail(size, Image.ANTIALIAS)		#Conforming data to dataset resolution
	#image1.show()
	data = image1.load()
	try:
		f = open("inputPic.txt", "w")			#writing picture as 0s and 1s to file for NN to feed forward
		
	except IOError:
		print("Could not write numbers to file")
		return


	for row in range(28):
		for pixel in range(28):
			if(row > 23 or pixel > 23 or pixel < 4 or row < 4):
				f.write("0")
			else:
				if data[row-4,pixel-4] ==1:
					f.write("1")
				else:
					f.write("0")
	f.close()
		
	os.system('start numberFind.exe')   #calling numberFind program
	
	result = -1
	notfound = True
	while notfound:
		try:
			output = open("output.txt", "r")
			for line in output:
				for x in line:
					result= x
					notfound = False
					
		except IOError:
			print("Could not read number from file")
			pass
	output.close()
	os.remove("output.txt")	
	os.remove("inputPic.txt")
	displayResult(result)
	print(result)
	

def displayResult(result):
	alert = Tk();
	popup = Window(alert)
	popup.config(title = "Number:", w=150, h=90)
	popup.positionWindow()

	def onExit():
		alert.destroy()
		return

	okButton = Button(alert, text = "Ok", command = onExit)
	printOut = Label(alert, text = result)
	printOut.pack()
	okButton.pack()

	alert.mainloop()
	
#========================================================================main function=========================================================================================

c = Canvas(root, bg="white", width=140, height= 140)

c.configure(cursor="crosshair")

c.pack()

button = Button(root, text = "What number is this?", command=getNumber)
button.pack()

c.bind("<B1-Motion>", point)

c.bind("<ButtonRelease-1>", stopDraw)

c.bind("<Button-3>", clear)



root.mainloop()