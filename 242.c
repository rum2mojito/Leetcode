

bool isAnagram(char * s, char * t){
    if(strlen(s) != strlen(t)) return false;
    
    int *origin_slots = (int*)calloc(26, sizeof(int));
    int *target_slots = (int*)calloc(26, sizeof(int));
    
    for(int i=0; i<strlen(s); i++) {
        origin_slots[s[i] - 'a']++;
        target_slots[t[i] - 'a']++;
    }
    
    for(int i=0; i<26; i++) {
        if(origin_slots[i] != target_slots[i]) return false;
    }
    
    return true;
}
