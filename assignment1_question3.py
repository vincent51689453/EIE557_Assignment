# Given samples
class1 = [(-1,0,1),(0,-1,1),(1,0,1),(0,1,1,)]
class2 = [(-2,0,1),(0,-2,1),(2,0,1),(-2,2,1,)]

# Initial weight
#w = [1,1,1]
w = [1,1,1]
dot_output = 0

# Training epoch
max_epoch = 10
index = 1
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
                print("w({}) . y({})={} -> w({}) = w({})".format(index,i+1,dot_output,index+1,index))
            else:
                a,b,c = vector_add(w,class1[i])
                w = [a,b,c]
                print("w({}) . y({})={} -> w({}) = w({}) + y({}) = {}".format(index,i+1,dot_output,index+1,index,i+1,w))

        else:
            i -= 4
            dot_output = dot_product(w,class2[i])
            if(dot_output < 0):
                print("w({}) . y({})={} -> w({}) = w({})".format(index,i+5,dot_output,index+1,index))
            else:
                a,b,c = vector_minus(w,class2[i])
                w = [a,b,c]    
                print("w({}) . y({})={} -> w({}) = w({}) - y({}) = {}".format(index,i+5,dot_output,index+1,index,i+5,w))     
        index += 1                   

    print("\r\n")
    epoch += 1