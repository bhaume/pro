import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB as gnb
from sklearn.metrics import accuracy_score
data = pd.read_csv('pima-indians-diabetes.csv')
print data.describe()
features = ['Pregnancies', 'Glucose', 'BloodPressure', 'SkinThickness', 'BMI', 'Age', 'Insulin', 'DiabetesPedigreeFunction']
target = 'Class'
train, test = train_test_split(data, test_size=0.2)
clf = gnb().fit(train[features], train[target]) 
y_predicted = clf.predict(test[features])
print "Accuracy ",round(accuracy_score(test[target], y_predicted)*100,2)," %"


# import pandas as pd
# from sklearn.naive_bayes import GaussianNB
# from sklearn.model_selection import train_test_split
# from sklearn.metrics import accuracy_score
# df = pd.read_csv("pima-indians-diabetes.csv")
# train,test = train_test_split(df,test_size=0.2)
# X = train.loc[:,"Pregnancies":"DiabetesPedigreeFunction"]
# y = train["Class"]
# X_test = test.loc[:,"Pregnancies":"DiabetesPedigreeFunction"]
# y_test = test["Class"]
# classifier = GaussianNB()
# #training
# classifier.fit(X,y)
# y_predicted = classifier.predict(X_test)
# score = accuracy_score(y_test,y_predicted)
# print "Accuracy ",score




#///////////////////////OUTPUT//////////////////////////////////////////////////////
# chanchald@chanchald-X553SA:~$ cd Desktop
# chanchald@chanchald-X553SA:~/Desktop$ cd p2
# chanchald@chanchald-X553SA:~/Desktop/p2$ python script.py
#        Pregnancies     Glucose  BloodPressure  SkinThickness         BMI  \
# count   768.000000  768.000000     768.000000     768.000000  768.000000   
# mean      3.845052  120.894531      69.105469      20.536458   79.799479   
# std       3.369578   31.972618      19.355807      15.952218  115.244002   
# min       0.000000    0.000000       0.000000       0.000000    0.000000   
# 25%       1.000000   99.000000      62.000000       0.000000    0.000000   
# 50%       3.000000  117.000000      72.000000      23.000000   30.500000   
# 75%       6.000000  140.250000      80.000000      32.000000  127.250000   
# max      17.000000  199.000000     122.000000      99.000000  846.000000   

#               Age     Insulin  DiabetesPedigreeFunction       Class  
# count  768.000000  768.000000                768.000000  768.000000  
# mean    31.992578    0.471876                 33.240885    0.348958  
# std      7.884160    0.331329                 11.760232    0.476951  
# min      0.000000    0.078000                 21.000000    0.000000  
# 25%     27.300000    0.243750                 24.000000    0.000000  
# 50%     32.000000    0.372500                 29.000000    0.000000  
# 75%     36.600000    0.626250                 41.000000    1.000000  
# max     67.100000    2.420000                 81.000000    1.000000  
# Accuracy  70.78  %
