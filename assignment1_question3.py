# Perceptron
# Given samples
class1 = [(-1,0,1),(0,-1,1),(1,0,1),(0,1,1,)]
print("Class1 vector{}".format(class1))
class2 = [(-2,0,1),(0,-2,1),(2,0,1),(-2,2,1,)]
print("Class2 vector{}".format(class2))

# Initial weight
#w = [1,1,1]
w = [1,-1,0]
dot_output = 0
print("Initial weight vector{}\r\n".format(w))

# Training epoch
max_epoch = 3
learning_rate = 0.1
index = 1
epoch = 0
correct = 0

def dot_product(A,B):
    i = A[0]*B[0]
    j = A[1]*B[1]
    k = A[2]*B[2]
    output = i+j+k
    output = round(output,3)
    return output

def vector_add(A,B,r):
    i = A[0]+r*B[0]
    j = A[1]+r*B[1]
    k = A[2]+r*B[2]
    i = round(i,3)
    j = round(j,3)
    k = round(k,3)
    return i,j,k

def vector_minus(A,B,r):
    i = A[0]-r*B[0]
    j = A[1]-r*B[1]
    k = A[2]-r*B[2]
    i = round(i,3)
    j = round(j,3)
    k = round(k,3)
    return i,j,k

while (epoch < max_epoch):
    # Start the epoch
    print("Iteration: {}/{}".format(epoch+1,max_epoch))
    for i in range(0,(len(class1)+len(class2))):
        if(i<=3):
            dot_output = dot_product(w,class1[i])
            if(dot_output > 0):
                print("w({}) . y({})={} -> w({}) = w({})".format(index,i+1,dot_output,index+1,index))
                correct += 1
            else:
                a,b,c = vector_add(w,class1[i],learning_rate)
                w = [a,b,c]
                #print("w({}) . y({})={} -> w({}) = w({}) + {}*y({}) = {}".format(index,i+1,dot_output,index+1,index,learning_rate,index,w))
                print("w({}) . y({})={} -> w({}) = w({}) + {}*y({}) = {}".format(index,i+1,dot_output,index+1,index,learning_rate,i+1,w))

        else:
            i -= 4
            dot_output = dot_product(w,class2[i])
            if(dot_output < 0):
                print("w({}) . y({})={} -> w({}) = w({})".format(index,i+5,dot_output,index+1,index))
                correct+=1
            else:
                a,b,c = vector_minus(w,class2[i],learning_rate)
                w = [a,b,c]    
                print("w({}) . y({})={} -> w({}) = w({}) - {}*y({}) = {}".format(index,i+5,dot_output,index+1,index,learning_rate,i+5,w))     
        index += 1                   
    print("Accuracy:{}".format(correct/8))
    print("\r\n")
    correct = 0
    epoch += 1

