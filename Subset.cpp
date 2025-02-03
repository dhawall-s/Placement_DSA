bool isSubset(vector<int> &a, vector<int> &b) {
    bool check = true;
    vector<int> result1;
    vector<int> result2;
    
    // Store elements instead of indices
    for (int i = 0; i < a.size(); i++) {
        result1.push_back(a[i]);
    }
    for (int j = 0; j < b.size(); j++) {
        result2.push_back(b[j]);
    }

    // Check if all elements of result1 exist in result2
    for (int i = 0; i < result1.size(); i++) {
        bool found = false;
        for (int j = 0; j < result2.size(); j++) {
            if (result1[i] == result2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            check = false;
            break;
        }
    }

    return check;
}
