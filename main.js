let time = {
    hr: 0,
    min: 0,
    sec:0
};

function updateTime(){
    time.sec++;
    if(time.sec>59){
        time.min++;
        time.sec=0;
    }
    if(time.min>59){
        time.hr++;
        time.min=0;
    }
    let hr = String(time.hr).padStart(2, '0');
    let min = String(time.min).padStart(2, '0');
    let sec = String(time.sec).padStart(2, '0');

    console.log(`${hr}:${min}:${sec}`);
}

setInterval(updateTime, 0.0001);