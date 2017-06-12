library(neuralnet)
library(RSNNS)
library(caTools)
set.seed(123)

dtcp <- read.csv("/home/secret95/Desktop/CN/tcp.csv", header=FALSE)
dudp <- read.csv("/home/secret95/Desktop/CN/udp.csv", header=FALSE)
dicmp <- read.csv("/home/secret95/Desktop/CN/icmp.csv", header=FALSE)

sample<-sample.split(dtcp,SplitRatio = 0.9)
trainset <- subset(dtcp,sample == TRUE)
testset <- subset(dtcp,sample == FALSE)
rd1<-trainset
rd2<-testset


sample<-sample.split(dudp,SplitRatio = 0.9)
trainset <- subset(dudp,sample == TRUE)
testset <- subset(dudp,sample == FALSE)


train1<-rbind(rd1,trainset)
test1<-rbind(rd2,testset)

sample<-sample.split(dicmp,SplitRatio = 0.9)
trainset <- subset(dicmp,sample == TRUE)
testset <- subset(dicmp,sample == FALSE)

trainDF<-rbind(train1,trainset)
testDF<-rbind(test1,testset)

hist(trainDF$V1)
hist(testDF$V1)

maxValue_train <- apply(trainDF,2,max)
minValue_train <- apply(trainDF,2,min)
trainDF <- as.data.frame(scale(trainDF,center = minValue_train,scale =
                                   maxValue_train - minValue_train))

maxValue_test <- apply(testDF,2,max)
minValue_test <- apply(testDF,2,min)
testDF <- as.data.frame(scale(testDF,center = minValue_test,scale =
                                 maxValue_train - minValue_test))
allVars<-colnames(trainDF)
predictorVars<-allVars[!allVars%in%"V1"]
predictorVars<-paste(predictorVars,collapse = "+")
print(predictorVars)
form=as.formula(paste("V1~",predictorVars,collapse = "+"))
neuralModel<-mlp(trainDF[,-1], trainDF$V1, size=8,
                 learnFuncParams=c(0.1),maxit =
                   5000,inputsTest=testDF[,-1],targetsTest=testDF$V1)
predictions<-predict(neuralModel,testDF[-1])
print(predictions)
str(predictions)
plot(testDF$V1,predictions,col='blue',main='Real vs
     Predicted',pch=1,cex=0.9,type="p",xlab="Actual",ylab = "Predicted")
abline(0,1,col='black')


predictedVals<-round(predictions, digits = 1)
actualVals<-testDF$V1
predictedVals<-replace(predictedVals,predictedVals==0.1,0.0)
predictedVals<-replace(predictedVals,predictedVals==0.2,0.0)
predictedVals<-replace(predictedVals,predictedVals==0.3,0.5)
predictedVals<-replace(predictedVals,predictedVals==0.4,0.5)
predictedVals<-replace(predictedVals,predictedVals==0.6,0.5)
predictedVals<-replace(predictedVals,predictedVals==0.7,0.5)
predictedVals<-replace(predictedVals,predictedVals==0.8,1.0)
predictedVals<-replace(predictedVals,predictedVals==0.9,1.0)

#confusion matrix
table(actualVals,predictedVals)
tab<-table(actualVals,predictedVals)
acc<-sum(diag(tab))*100/sum(tab)
acc

tcp_precision_numerator <- matrix[1]
tcp_precision_denominator <- matrix[1] + matrix[2] + matrix[3]
tcp_precision <- tcp_precision_numerator / tcp_precision_denominator
tcp_precision

udp_precision_numerator <- matrix[5]
udp_precision_denominator <- matrix[5] + matrix[4] + matrix[6]
udp_precision <- udp_precision_numerator / udp_precision_denominator
udp_precision

icmp_precision_numerator <- matrix[9]
icmp_precision_denominator <- matrix[9] + matrix[7] + matrix[8]
icmp_precision <- icmp_precision_numerator / icmp_precision_denominator
icmp_precision

precision <- c(tcp_precision, udp_precision, icmp_precision)

#recall
tcp_recall_numerator <- matrix[1]
tcp_recall_denominator <- matrix[1] + (matrix[5] + matrix[6] + matrix[8] + matrix[9])
tcp_recall <- tcp_recall_numerator / tcp_recall_denominator
tcp_recall

udp_recall_numerator <- matrix[5]
udp_recall_denominator <- matrix[5] + (matrix[1] + matrix[3] + matrix[7] + matrix[9])
udp_recall <- udp_recall_numerator / udp_recall_denominator
udp_recall

icmp_recall_numerator <- matrix[9]
icmp_recall_denominator <- matrix[9] + (matrix[1] + matrix[2] + matrix[4] + matrix[5])
icmp_recall <- icmp_recall_numerator / icmp_recall_denominator
icmp_recall

recall <- c(tcp_recall, udp_recall, icmp_recall)

#f-measure
tcp_fmeasure_numerator <- 2 * tcp_precision * tcp_recall
tcp_fmeasure_denominator <- tcp_precision + tcp_recall
tcp_fmeasure <- tcp_fmeasure_numerator / tcp_fmeasure_denominator

udp_fmeasure_numerator <- 2 * udp_precision * udp_recall
udp_fmeasure_denominator <- udp_precision + udp_recall
udp_fmeasure <- udp_fmeasure_numerator / udp_fmeasure_denominator

icmp_fmeasure_numerator <- 2 * icmp_precision * icmp_recall
icmp_fmeasure_denominator <- icmp_precision + icmp_recall
icmp_fmeasure <- icmp_fmeasure_numerator / icmp_fmeasure_denominator

fmeasure <- c(tcp_fmeasure, udp_fmeasure, icmp_fmeasure)

#print vals
MSE
acc
precision
recall
fmeasure
