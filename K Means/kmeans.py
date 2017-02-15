import matplotlib.pyplot as plt
import random
import math
 
c1=[]
c2=[]
c3=[]
c4=[]
c5=[]
center=[]
points=[]

def centroid(points,center):
	n1=len(c1)
	n2=len(c2)
	n3=len(c3)
	n4=len(c4)
	n5=len(c5)
	
	nx=0
	ny=0
	for i in range(0,n1):
		nx=nx+c1[i][0]
		ny=ny+c1[i][1]
	center[0][0]=nx/n1
	center[0][1]=ny/n2

	nx=0
	ny=0

	for i in range(0,n2):
		nx=nx+c2[i][0]
		ny=ny+c2[i][1]
	center[1][0]=nx/n1
	center[1][1]=ny/n2

	nx=0
	ny=0

	for i in range(0,n3):
		nx=nx+c3[i][0]
		ny=ny+c3[i][1]
	center[2][0]=nx/n1
	center[2][1]=ny/n2

	nx=0
	ny=0
	
	for i in range(0,n4):
		nx=nx+c4[i][0]
		ny=ny+c4[i][1]
	center[3][0]=nx/n1
	center[3][1]=ny/n2

	nx=0
	ny=0
	for i in range(0,n5):
		nx=nx+c5[i][0]
		ny=ny+c5[i][1]
	center[4][0]=nx/n1
	center[4][1]=ny/n2

	return;


def distance(points,center):
	for x in xrange(1,10):
		for i in range(0,100):
			x=points[i][0]
 			y=points[i][1]

 			c1x=center[0][0]
 			c1y=center[0][1]

 			c2x=center[1][0]
 			c2y=center[1][1]

 			c3x=center[2][0]
 			c3y=center[2][1]

 			c4x=center[3][0]
 			c4y=center[3][1]

 			c5x=center[4][0]
 			c5y=center[4][1]

 			d1=math.sqrt((pow((c1x-x),2)) + (pow((c1y-y),2)))
 			d2=math.sqrt((pow((c2x-x),2)) + (pow((c2y-y),2)))
 			d3=math.sqrt((pow((c3x-x),2)) + (pow((c3y-y),2)))
 			d4=math.sqrt((pow((c4x-x),2)) + (pow((c4y-y),2)))
 			d5=math.sqrt((pow((c5x-x),2)) + (pow((c5y-y),2)))

 			d=min(d1,d2,d3,d4,d5)
 			cluster=[]
 		
 			if d==d1:
 				c1.append([x,y])
 				plt.scatter(x, y, color='blue')
 			elif d==d2:
 				c2.append([x,y])
 				plt.scatter(x,y,color='red')
 			elif d==d3:
 				c3.append([x,y])
 				plt.scatter(x,y,color='black')
 			elif d==d4:
 				c4.append([x,y])
 				plt.scatter(x,y,color='green')
 			elif d==d5:
 				c5.append([x,y])
 				plt.scatter(x,y,color='orange')	


 		centroid(points,center)
		
	return ;

#create 100 random points

for i in range(0,100):
	x=random.randint(0,100)
	y=random.randint(0,100)
	points.append([x,y])
	plt.scatter(x, y)
	
#initialize 5 initial centroids

for i in range(0,5):
	x=random.randint(0,100)
	y=random.randint(0,100)
	center.append([x,y])

distance(points,center)
plt.show()




