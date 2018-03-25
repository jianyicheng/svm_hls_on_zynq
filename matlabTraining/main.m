% Load the data and select features for classification
load data

N = 20000;   % number of data to be used for training

% Get a smaller set of the data
data = data(1:N,:);
label = label(1:N,:);
uniqueLabels = unique(label);

%for i=1:length(uniqueLabels)
%    targetLetter = uniqueLabels(i)
targetLetter = 'E';

X = data - 8; % In order to bring the data in the range (-8,8)
% Extract the target class
Y = nominal(ismember(label,targetLetter));
% Randomly partitions observations into a training set and a test
% set using stratified holdout
P = cvpartition(Y,'Holdout',0.1);
% Use a linear support vector machine classifier
svmStruct = svmtrain(X(P.training,:),Y(P.training),'autoscale',true, 'kernel_function',@kfun);
C = svmclassify(svmStruct,X(P.test,:),'showplot',false);
errRate = sum(Y(P.test)~= C)/P.TestSize  %mis-classification rate
conMat = confusionmat(Y(P.test),C) % the confusion matrix

%end

% Generate (scale) test data
testData = X(P.test,:);
shift = svmStruct.ScaleData.shift;
scaleFactor = svmStruct.ScaleData.scaleFactor;
for i=1:size(testData,1)
    testData(i,:) = testData(i,:) + shift;
    testData(i,:) = testData(i,:) .* scaleFactor;
end
testData = testData';
temp = Y(P.test);
testDataLabel = (temp == 'true');

% Part of the code that generates the files.
% Support Vector. Every 16 entries correspond to a support vector
% Total SVs = 6191
SV = svmStruct.SupportVectors;
SV = SV';
fid = fopen('SV.h','w');
fprintf(fid,'// Structure that stores the SVs\n');
fprintf(fid,'// Each vector has 16 elements, and all the SVs have been concatenated\n');
fprintf(fid,'// There are %d SVs\n\n', size(SV,2));
fprintf(fid,'double SVs[] = {');
fprintf(fid,'%3.6f,\n',SV(:));
fprintf(fid,'};\n');
fclose(fid);

% Alpha values. One entry per SV
alpha = svmStruct.Alpha;
length(alpha)
fid = fopen('alpha.h','w');
fprintf(fid,'double alpha[] = {');
fprintf(fid,'%3.6f,\n',alpha(:));
fprintf(fid,'};\n');
fprintf(fid,'\n\n');

% Append the bias
fprintf(fid,'double bias = %f;\n',svmStruct.Bias);
fclose(fid);

% The test file
fid = fopen('testData.h','w');
fprintf(fid,'double testData[] = {');
fprintf(fid,'%3.6f,\n',testData(:));
fprintf(fid,'};\n');
fprintf(fid,'\n\n');

fprintf(fid,'int testDataLabel[] = {');
fprintf(fid,'%d,\n',testDataLabel(:));
fprintf(fid,'};\n');

fclose(fid);

