

from matplotlib import pyplot as plt
import numpy as np


fig,ax = plt.subplots(10,2)
im = plt.imread("BlueUD.bmp")
arr = np.random.rand(32,32)
arr=np.uint8(arr)
im1 = plt.imread("Yellow.bmp")
arr1 = np.random.rand(32,32)
arr1=np.uint8(arr1)
im2 = plt.imread("OrangeUD.bmp")
arr2 = np.random.rand(32,32)
arr2=np.uint8(arr2)
im3 = plt.imread("PurpleUD.bmp")
arr3 = np.random.rand(32,32)
arr3=np.uint8(arr3)
im4 = plt.imread("GreenUD.bmp")
arr4 = np.random.rand(32,32)
arr4=np.uint8(arr4)
im5 = plt.imread("CoconutWheel.bmp")
arr5 = np.random.rand(32,32)
arr5=np.uint8(arr5)
im6 = plt.imread("OrbR.bmp")
arr6 = np.random.rand(32,32)
arr6=np.uint8(arr6)
im7 = plt.imread("Donut.bmp")
arr7 = np.random.rand(32,32)
arr7=np.uint8(arr7)
im8 = plt.imread("Chocolate.bmp")
arr8 = np.random.rand(32,32)
arr8=np.uint8(arr8)
im9 = plt.imread("RedUD.bmp")
arr9 = np.random.rand(32,32)
arr9=np.uint8(arr9)

im_r  = im[:,:,0]
im_g  = im[:,:,1]
im_b  = im[:,:,2]
im1_r = im1[:,:,0]
im1_g = im1[:,:,1]
im1_b = im1[:,:,2]
im2_r = im2[:,:,0]
im2_g = im2[:,:,1]
im2_b = im2[:,:,2]
im3_r = im3[:,:,0]
im3_g = im3[:,:,1]
im3_b = im3[:,:,2]
im4_r = im4[:,:,0]
im4_g = im4[:,:,1]
im4_b = im4[:,:,2]
im5_r = im5[:,:,0]
im5_g = im5[:,:,1]
im5_b = im5[:,:,2]
im6_r = im6[:,:,0]
im6_g = im6[:,:,1]
im6_b = im6[:,:,2]
im7_r = im7[:,:,0]
im7_g = im7[:,:,1]
im7_b = im7[:,:,2]
im8_r = im8[:,:,0]
im8_g = im8[:,:,1]
im8_b = im8[:,:,2]
im9_r = im9[:,:,0]
im9_g = im9[:,:,1]
im9_b = im9[:,:,2]


r=0
c=0
for r in range (32):
    for c in range (32):
        if  im_r[r][c] == 255:         
            rtemp=7 
        if 254>= im_r[r][c] >= 161:
            rtemp=6                      
        if 160>= im_r[r][c] >=128:
            rtemp=5      
        if 127>= im_r[r][c] >=96:
            rtemp=4 
        if 95>= im_r[r][c] >= 64:
            rtemp=3
        if 63>= im_r[r][c] >=20:
            rtemp=2
        if 19>= im_r[r][c] >= 1:
            rtemp=1
        if  im_r[r][c] == 0:
            rtemp=0
        if im_g[r][c] == 255:
            gtemp=7     
        if 254>= im_g[r][c] >= 192:
            gtemp=6   
        if 191>= im_g[r][c] >=160:
            gtemp=5 
        if 159>= im_g[r][c] >=128:
            gtemp=4
        if 127>= im_g[r][c] >= 96:
            gtemp=3
        if 95>= im_g[r][c] >= 64:
            gtemp=2
        if 63>= im_g[r][c] >= 1:
            gtemp=1
        if im_g[r][c] == 0:
            gtemp=0
        if  im_b[r][c] ==255:
            btemp=3
        if 254>= im_b[r][c] >= 128:
            btemp=2
        if 127>= im_b[r][c] >=1:
            btemp=1
        if  im_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) + (gtemp << 2 ) + (btemp )
        arr[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','w') as fp:
    fp.write("#ifndef ICON_H_ \n") 
    fp.write("#define ICON_H_ \n") 
    fp.write("unsigned char ICON00[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
    
for r in range (32):
    for c in range (32):
        if  im1_r[r][c] == 255:         
            rtemp=7 
        if 254>= im1_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im1_r[r][c] >=160:
            rtemp=5      
        if 159>= im1_r[r][c] >=128:
            rtemp=4 
        if 127>= im1_r[r][c] >= 96:
            rtemp=3
        if 95>= im1_r[r][c] >= 64:
            rtemp=2
        if 63>= im1_r[r][c] >= 1:
            rtemp=1
        if  im1_r[r][c] == 0:
            rtemp=0
        if im1_g[r][c] == 255:
            gtemp=7     
        if 254>= im1_g[r][c] >= 192:
            gtemp=6   
        if 191>= im1_g[r][c] >=160:
            gtemp=5 
        if 159>= im1_g[r][c] >=128:
            gtemp=4
        if 127>= im1_g[r][c] >= 96:
            gtemp=3
        if 95>= im1_g[r][c] >= 64:
            gtemp=2
        if 63>= im1_g[r][c] >= 1:
            gtemp=1
        if im1_g[r][c] == 0:
            gtemp=0
        if  im1_b[r][c] ==255:
            btemp=3
        if 254>= im1_b[r][c] >= 128:
            btemp=2
        if 127>= im1_b[r][c] >=1:
            btemp=1
        if  im1_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr1[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON01[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr1[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
for r in range (32):
    for c in range (32):
        if  im2_r[r][c] == 255:         
            rtemp=7 
        if 254>= im2_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im2_r[r][c] >=160:
            rtemp=5      
        if 159>= im2_r[r][c] >=128:
            rtemp=4 
        if 127>= im2_r[r][c] >= 96:
            rtemp=3
        if 95>= im2_r[r][c] >= 64:
            rtemp=2
        if 63>= im2_r[r][c] >= 1:
            rtemp=1
        if  im2_r[r][c] == 0:
            rtemp=0
        if im2_g[r][c] == 255:
            gtemp=7     
        if 254>= im2_g[r][c] >= 192:
            gtemp=6   
        if 191>= im2_g[r][c] >=160:
            gtemp=5 
        if 159>= im2_g[r][c] >=128:
            gtemp=4
        if 127>= im2_g[r][c] >= 96:
            gtemp=3
        if 95>= im2_g[r][c] >= 64:
            gtemp=2
        if 63>= im2_g[r][c] >= 1:
            gtemp=1
        if im2_g[r][c] == 0:
            gtemp=0
        if  im2_b[r][c] ==255:
            btemp=3
        if 254>= im2_b[r][c] >= 128:
            btemp=2
        if 127>= im2_b[r][c] >=1:
            btemp=1
        if  im2_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr2[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON02[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr2[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
for r in range (32):
    for c in range (32):
        if  im3_r[r][c] == 255:         
            rtemp=7 
        if 254>= im3_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im3_r[r][c] >=160:
            rtemp=5      
        if 159>= im3_r[r][c] >=128:
            rtemp=4 
        if 127>= im3_r[r][c] >= 96:
            rtemp=3
        if 95>= im3_r[r][c] >= 64:
            rtemp=2
        if 63>= im3_r[r][c] >= 1:
            rtemp=1
        if  im3_r[r][c] == 0:
            rtemp=0
        if im3_g[r][c] == 255:
            gtemp=7     
        if 254>= im3_g[r][c] >= 192:
            gtemp=6   
        if 191>= im3_g[r][c] >=160:
            gtemp=5 
        if 159>= im3_g[r][c] >=128:
            gtemp=4
        if 127>= im3_g[r][c] >= 96:
            gtemp=3
        if 95>= im3_g[r][c] >= 64:
            gtemp=2
        if 63>= im3_g[r][c] >= 1:
            gtemp=1
        if im3_g[r][c] == 0:
            gtemp=0
        if  im3_b[r][c] ==255:
            btemp=3
        if 254>= im3_b[r][c] >= 128:
            btemp=2
        if 127>= im3_b[r][c] >=1:
            btemp=1
        if  im3_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr3[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON03[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr3[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
for r in range (32):
    for c in range (32):
        if  im4_r[r][c] == 255:         
            rtemp=7 
        if 254>= im4_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im4_r[r][c] >=160:
            rtemp=5      
        if 159>= im4_r[r][c] >=128:
            rtemp=4 
        if 127>= im4_r[r][c] >= 96:
            rtemp=3
        if 95>= im4_r[r][c] >= 64:
            rtemp=2
        if 63>= im4_r[r][c] >= 1:
            rtemp=1
        if  im4_r[r][c] == 0:
            rtemp=0
        if im4_g[r][c] == 255:
            gtemp=7     
        if 254>= im4_g[r][c] >= 192:
            gtemp=6   
        if 191>= im4_g[r][c] >=160:
            gtemp=5 
        if 159>= im4_g[r][c] >=128:
            gtemp=4
        if 127>= im4_g[r][c] >= 96:
            gtemp=3
        if 95>= im4_g[r][c] >= 64:
            gtemp=2
        if 63>= im4_g[r][c] >= 1:
            gtemp=1
        if im4_g[r][c] == 0:
            gtemp=0
        if  im4_b[r][c] ==255:
            btemp=3
        if 254>= im4_b[r][c] >= 128:
            btemp=2
        if 127>= im4_b[r][c] >=1:
            btemp=1
        if  im4_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr4[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON04[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr4[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
# 5th image
for r in range (32):
    for c in range (32):
        if  im5_r[r][c] == 255:         
            rtemp=7 
        if 254>= im5_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im5_r[r][c] >=160:
            rtemp=5      
        if 159>= im5_r[r][c] >=128:
            rtemp=4 
        if 127>= im5_r[r][c] >= 96:
            rtemp=3
        if 95>= im5_r[r][c] >= 64:
            rtemp=2
        if 63>= im5_r[r][c] >= 1:
            rtemp=1
        if  im5_r[r][c] == 0:
            rtemp=0
        if im5_g[r][c] == 255:
            gtemp=7     
        if 254>= im5_g[r][c] >= 192:
            gtemp=6   
        if 191>= im5_g[r][c] >=160:
            gtemp=5 
        if 159>= im5_g[r][c] >=128:
            gtemp=4
        if 127>= im5_g[r][c] >= 96:
            gtemp=3
        if 95>= im5_g[r][c] >= 64:
            gtemp=2
        if 63>= im5_g[r][c] >= 1:
            gtemp=1
        if im5_g[r][c] == 0:
            gtemp=0
        if  im5_b[r][c] ==255:
            btemp=3
        if 254>= im5_b[r][c] >= 128:
            btemp=2
        if 127>= im5_b[r][c] >=1:
            btemp=1
        if  im5_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr5[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON05[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr5[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
# 6th image
for r in range (32):
    for c in range (32):
        if  im6_r[r][c] == 255:         
            rtemp=7 
        if 254>= im6_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im6_r[r][c] >=160:
            rtemp=5      
        if 159>= im6_r[r][c] >=128:
            rtemp=4 
        if 127>= im6_r[r][c] >= 96:
            rtemp=3
        if 95>= im6_r[r][c] >= 64:
            rtemp=2
        if 63>= im6_r[r][c] >= 1:
            rtemp=1
        if  im6_r[r][c] == 0:
            rtemp=0
        if im6_g[r][c] == 255:
            gtemp=7     
        if 254>= im6_g[r][c] >= 192:
            gtemp=6   
        if 191>= im6_g[r][c] >=160:
            gtemp=5 
        if 159>= im6_g[r][c] >=128:
            gtemp=4
        if 127>= im6_g[r][c] >= 96:
            gtemp=3
        if 95>= im6_g[r][c] >= 64:
            gtemp=2
        if 63>= im6_g[r][c] >= 1:
            gtemp=1
        if im6_g[r][c] == 0:
            gtemp=0
        if  im6_b[r][c] ==255:
            btemp=3
        if 254>= im6_b[r][c] >= 128:
            btemp=2
        if 127>= im6_b[r][c] >=1:
            btemp=1
        if  im6_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr6[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON06[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr6[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
# 7th 
for r in range (32):
    for c in range (32):
        if  im7_r[r][c] == 255:         
            rtemp=7 
        if 254>= im7_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im7_r[r][c] >=160:
            rtemp=5      
        if 159>= im7_r[r][c] >=128:
            rtemp=4 
        if 127>= im7_r[r][c] >= 96:
            rtemp=3
        if 95>= im7_r[r][c] >= 64:
            rtemp=2
        if 63>= im7_r[r][c] >= 1:
            rtemp=1
        if  im7_r[r][c] == 0:
            rtemp=0
        if im7_g[r][c] == 255:
            gtemp=7     
        if 254>= im7_g[r][c] >= 192:
            gtemp=6   
        if 191>= im7_g[r][c] >=160:
            gtemp=5 
        if 159>= im7_g[r][c] >=128:
            gtemp=4
        if 127>= im7_g[r][c] >= 96:
            gtemp=3
        if 95>= im7_g[r][c] >= 64:
            gtemp=2
        if 63>= im7_g[r][c] >= 1:
            gtemp=1
        if im7_g[r][c] == 0:
            gtemp=0
        if  im7_b[r][c] ==255:
            btemp=3
        if 254>= im7_b[r][c] >= 128:
            btemp=2
        if 127>= im7_b[r][c] >=1:
            btemp=1
        if  im7_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr7[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON07[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr7[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
# 8th 
for r in range (32):
    for c in range (32):
        if  im8_r[r][c] == 255:         
            rtemp=7 
        if 254>= im8_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im8_r[r][c] >=160:
            rtemp=5      
        if 159>= im8_r[r][c] >=128:
            rtemp=4 
        if 127>= im8_r[r][c] >= 96:
            rtemp=3
        if 95>= im8_r[r][c] >= 64:
            rtemp=2
        if 63>= im8_r[r][c] >= 1:
            rtemp=1
        if  im8_r[r][c] == 0:
            rtemp=0
        if im8_g[r][c] == 255:
            gtemp=7     
        if 254>= im8_g[r][c] >= 192:
            gtemp=6   
        if 191>= im8_g[r][c] >=160:
            gtemp=5 
        if 159>= im8_g[r][c] >=128:
            gtemp=4
        if 127>= im8_g[r][c] >= 96:
            gtemp=3
        if 95>= im8_g[r][c] >= 64:
            gtemp=2
        if 63>= im8_g[r][c] >= 1:
            gtemp=1
        if im8_g[r][c] == 0:
            gtemp=0
        if  im8_b[r][c] ==255:
            btemp=3
        if 254>= im8_b[r][c] >= 128:
            btemp=2
        if 127>= im8_b[r][c] >=1:
            btemp=1
        if  im8_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr8[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON08[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr8[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
# 9th
for r in range (32):
    for c in range (32):
        if  im9_r[r][c] == 255:         
            rtemp=7 
        if 254>= im9_r[r][c] >= 192:
            rtemp=6                      
        if 191>= im9_r[r][c] >=160:
            rtemp=5      
        if 159>= im9_r[r][c] >=128:
            rtemp=4 
        if 127>= im9_r[r][c] >= 96:
            rtemp=3
        if 95>= im9_r[r][c] >= 64:
            rtemp=2
        if 63>= im9_r[r][c] >= 1:
            rtemp=1
        if  im9_r[r][c] == 0:
            rtemp=0
        if im9_g[r][c] == 255:
            gtemp=7     
        if 254>= im9_g[r][c] >= 192:
            gtemp=6   
        if 191>= im9_g[r][c] >=160:
            gtemp=5 
        if 159>= im9_g[r][c] >=128:
            gtemp=4
        if 127>= im9_g[r][c] >= 96:
            gtemp=3
        if 95>= im9_g[r][c] >= 64:
            gtemp=2
        if 63>= im9_g[r][c] >= 1:
            gtemp=1
        if im9_g[r][c] == 0:
            gtemp=0
        if  im9_b[r][c] ==255:
            btemp=3
        if 254>= im9_b[r][c] >= 128:
            btemp=2
        if 127>= im9_b[r][c] >=1:
            btemp=1
        if  im9_b[r][c] == 0:
            btemp=0
        byte1 =  (rtemp << 5) | (gtemp << 2 ) | (btemp )
        arr9[r][c]=byte1
        c=c+1
        byte1=0          
    r=r+1
with open('ICON.h','a') as fp:
    fp.write("unsigned char ICON09[32][32] = { \n")  
    for r in range (32):
        fp.write("{")
        for c in range (32):
            x=hex(arr9[r][c])
            fp.write(x)
            if( c <31):
                fp.write(",")
        fp.write("},\n")        
    fp.write("};\n")
    fp.write("#endif\n")
         

ax[0][0].imshow(arr)
ax[0][1].imshow(im)
ax[2][0].imshow(arr1)
ax[2][1].imshow(im1)
ax[3][0].imshow(arr2)
ax[3][1].imshow(im2)
ax[4][0].imshow(arr3)
ax[4][1].imshow(im3)
ax[5][0].imshow(arr4)
ax[5][1].imshow(im4)
ax[6][0].imshow(arr5)
ax[6][1].imshow(im5)
ax[7][0].imshow(arr6)
ax[7][1].imshow(im6)
ax[8][0].imshow(arr7)
ax[8][1].imshow(im7)
ax[9][0].imshow(arr8)
ax[9][1].imshow(im8)
ax[1][0].imshow(arr9)
ax[1][1].imshow(im9)


# ax[0].imshow(im3, cmap = 'gray')        
# ax[0].set_xticks([])
# ax[0].set_yticks([])
# ax[0].set_title('AVERAGE')


# im2=(im0[:,:,0]*0.299+ im0[:,:,1]*0.587+im0[:,:,2]*0.114)
# im4= np.uint8(im2*255)
# ax[1].imshow(im4, cmap = 'gray')        
# ax[1].set_xticks([])
# ax[1].set_yticks([])
# ax[1].set_title('weigted')
