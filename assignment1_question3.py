# Given samples
class1 = [(-1,0,1),(0,-1,1),(1,0,1),(0,1,1,)]
class2 = [(-2,0,1),(0,-2,1),(2,0,1),(-2,2,1,)]

# Initial weight
w = [1,1,1]
dot_output = 0

# Training epoch
max_epoch = 10
epoch = 0

def dot_product(A,B):
    i = A[0]*B[0]
    j = A[1]*B[1]
    k = A[2]*B[2]
    output = i+j+k
    return output

def vector_add(A,B):
    i = A[0]+B[0]
    j = A[1]+B[1]
    k = A[2]+B[2]
    return i,j,k

def vector_minus(A,B):
    i = A[0]-B[0]
    j = A[1]-B[1]
    k = A[2]-B[2]
    return i,j,k

while (epoch < max_epoch):
    # Start the epoch
    print("Iteration: {}\r\n".format(epoch+1))
    for i in range(0,(len(class1)+len(class2))):
        if(i<=3):
            dot_output = dot_product(w,class1[i])
            if(dot_output > 0):
                print("w({}) . y({})={} -> w({}) = w({})".format(i+1,i+1,dot_output,i+2,i+1))
            elif(dot_output == 0):
                a,b,c = vector_add(w,class1[i])
                w = [a,b,c]
                print("w({}) . y({})={} -> w({}) = w({}) + y({}) = {}".format(i+1,i+1,dot_output,i+2,i+1,i+1,w))
            else:
                a,b,c = vector_minus(w,class1[i])
                w = [a,b,c]    
                print("w({}) . y({})={} -> w({}) = w({}) - y({}) = {}".format(i+1,i+1,dot_output,i+2,i+1,i+1,w))    
        else:
            i -= 4
            dot_output = dot_product(w,class2[i])
            if(dot_output < 0):
                print("w({}) . y({})={} -> w({}) = w({})".format(i+5,i+5,dot_output,i+6,i+5))
            elif(dot_output == 0):
                a,b,c = vector_add(w,class2[i])
                w = [a,b,c]
                print("w({}) . y({})={} -> w({}) = w({}) + y({}) = {}".format(i+5,i+5,dot_output,i+6,i+5,i+5,w))
            else:
                a,b,c = vector_minus(w,class2[i])
                w = [a,b,c]    
                print("w({}) . y({})={} -> w({}) = w({}) - y({}) = {}".format(i+5,i+5,dot_output,i+6,i+5,i+5,w))                        

    print("\r\n")
    epoch += 1