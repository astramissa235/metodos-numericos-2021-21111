//GAUSS-JORDAN

/*
 2x +y -z  =  8
-3x -y +2z = -11
-2x +y +2z = -3
*/

ecuationMatrixLeftSide = [2 1 -1; -3 -1 2; -2 1 2]
ecuationMatrixRigthSide = [8;-11;-3]

//Build Augmented Matrix and extract row and column sizes
augmentedMatrix = [ecuationMatrixLeftSide ecuationMatrixRigthSide]
[augmentedMatrixRowSize augmentedMatrixColSize] = size(augmentedMatrix)

//Show the Augmented Matrix that was built
disp("Augmented Matrix")
disp(augmentedMatrix)

//Gauss-Jordan Elimination of variables over augmented Matrix to reduce it
for p = 1:1:augmentedMatrixRowSize-1
    pivot = augmentedMatrix(p,p);
    for i = p+1: 1: augmentedMatrixRowSize
        primFila = augmentedMatrix(i,p)
        augmentedMatrix(i,:) = augmentedMatrix(i,:) - (augmentedMatrix(p, :)/pivot)*primFila
    end
end

for i = augmentedMatrixRowSize: -1: 2
    pivot = augmentedMatrix(i, i)
    for j = i-1: -1: 1
        primFila = augmentedMatrix(j, i)
        augmentedMatrix(j, :) = augmentedMatrix(j, :) - (augmentedMatrix(i, :)/pivot)*primFila
    end
end

for i = 1: augmentedMatrixRowSize
    f = augmentedMatrix(i, i)
    augmentedMatrix(i, :) = augmentedMatrix(i, :)/f
end

//Show the reduced Augmented matrix obtained
disp("Reduced Augmented matrix")
disp(augmentedMatrix)

//Accumulate obtained solutions to the ecuation system
sol = ""
for i = 1: augmentedMatrixRowSize
        sol = sol + " var" + string(i) + " = " + string(augmentedMatrix(i, augmentedMatrixColSize)) +","
end

disp("Ecuation Solutions")
disp(sol)
