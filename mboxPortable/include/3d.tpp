template <typename T, int row, int column>
mat<T, row, column> mbox::transform::translate(const mat<T, row, column>& mat, const vec<T, row-1>& vect, bool direction){
    mbox::mat<T, row, column> temp(mat);
    int m = row-1; 
    int n = column - 1;
    if(!direction)
        temp.updateElement(m, n, 1);
    for(int i = 0; i < m; i++){
        for(int j = n; j<=n; j++){
            temp.updateElement(i, j, vect.getElement(i));
        }
    }
    temp.transpose();
    return temp;
}

template <typename T, int row, int column>
mat<T, row, column> mbox::transform::scale(const mat<T, row, column>& mat, const vec<T, row-1>& vect, bool direction){
    mbox::mat<T, row, column> temp(mat);
    int m = row-1; 
    int n = column - 1;
    if(!direction)
        temp.updateElement(m, n, 1);
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(i == j)
                temp.updateElement(i, j, vect.getElement(i));
        }
    }
    return temp;
}