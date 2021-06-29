//Gauss Elimination

/*
 2x +y -z  =  8
-3x -y +2z = -11
-2x +y +2z = -3
*/

ecuationMatrixLeftSide = [2 1 -1; -3 -1 2; -2 1 2]
ecuationMatrixRigthSide = [8;-11;-3]
solutions = []

//Build Augmented Matrix and extract row and column sizes
augmentedMatrix = [ecuationMatrixLeftSide ecuationMatrixRigthSide]
[augmentedMatrixRowSize augmentedMatrixColSize] = size(augmentedMatrix)

//Show the Augmented Matrix that was built
disp("Augmented Matrix")
disp(augmentedMatrix)

//Gaussian Elimination of variables over augmented Matrix to reduce it
for p = 1:1:augmentedMatrixRowSize-1
    pivot = augmentedMatrix(p,p);
    for i = p+1: 1: augmentedMatrixRowSize
        primFila = augmentedMatrix(i,p)
        augmentedMatrix(i, :) = augmentedMatrix(i, :) - (augmentedMatrix(p, :)/pivot)*primFila
    end
end

//Show the reduced Augmented matrix obtained
disp("Reduced Augmented Matrix")
disp(augmentedMatrix)

//Substition to find solutions to the ecuation system
solutions(augmentedMatrixRowSize) = augmentedMatrix(augmentedMatrixRowSize, augmentedMatrixColSize)/augmentedMatrix(augmentedMatrixRowSize, augmentedMatrixColSize-1)
for i = augmentedMatrixRowSize-1: -1: 1
    s = augmentedMatrix(i, augmentedMatrixColSize)
    for j = augmentedMatrixRowSize: -1: i
        s = s - augmentedMatrix(i, j)*solutions(j)
    end
    solutions(i) = s/augmentedMatrix(i, i)
end

//Accumulate variable solutions to the ecuation system
sol = ""
for i = 1: augmentedMatrixRowSize
    sol = sol +" var" + string(i) + " = " + string(solutions(i)) +","
end

disp("Ecuation Solutions")
disp(sol)
