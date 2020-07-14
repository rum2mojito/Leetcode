

double angleClock(int hour, int minutes){
    if(hour > 11) hour = 0;
    double hour_degree = hour*30 + minutes*(0.5);
    double minutes_degree = minutes*6;
    
    if(minutes_degree - hour_degree > 180) return 360 - (minutes_degree - hour_degree);
    else if(hour_degree - minutes_degree > 180) return 360 - (hour_degree - minutes_degree);
    
    if(minutes_degree > hour_degree) return minutes_degree - hour_degree;
    return hour_degree - minutes_degree;
}
