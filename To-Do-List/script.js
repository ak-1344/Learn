const today = new Date();

const t_date = today.getDate();
const t_month = today.getMonth();
const t_year = today.getFullYear();

const months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

//Making elements
let sidebar = {
    date: document.querySelector("#date-in-box1 > span"),
    month: document.querySelector("#sidebar-month"),
    year: document.querySelector("#sidebar-year")
};
const main_calender = document.querySelector(".month");
const days_calender = document.querySelector(".days");

//Setting sidebar
sidebar.date.innerHTML = t_date >= 10 ? t_date : "0" + t_date;
sidebar.month.innerHTML = months[t_month];
sidebar.year.innerHTML = t_year;

let currentDate = new Date();
function renderCalender() {
    //Getting first date of the month
    currentDate.setDate(1); //first date of the month
    const month = currentDate.getMonth();
    const year = currentDate.getFullYear();

    //Finding the details of first day of the month
    const first_day = currentDate.getDay();


    // Details of last day
    const last_day = new Date(year, month + 1, 0).getDate();

    //Details of last day of previous month
    const prev_month_last_day = new Date(year, month, 0).getDate();

    //Setting the head of calender as the given month
    main_calender.innerHTML = months[month] + " " + year;


    let days = "";

    for (let i = first_day; i > 0; i--) {
        days += `<button class="dates-double dates-faded">${prev_month_last_day - i + 1}</button>\n`;
    }
    for (let i = 1; i <= last_day; i++) {
        let valid = (i === new Date().getDate() && month === new Date().getMonth() && year === new Date().getFullYear()) ? true : false;

        if (valid) {
            if (i > 9) {
                days += `<button class="today dates-double">${i}</button>`;
            }
            else {
                days += `<button class="today dates">${i}</button>`;
            }
        } else {
            if (i > 9) {
                days += `<button class="dates-double">${i}</button>`;
            }
            else {
                days += `<button class="dates">${i}</button>`;
            }
        }
    }
    let nextDay = 35 - (first_day + last_day);
    if (first_day+last_day > 35) {
        nextDay = 42 - (first_day + last_day);
    }

    for (let i = 1; i <= nextDay; i++) {
        i < 10 ? days += `<button class="dates-faded">${i}</button>` : days += `<button class="dates-faded dates-double">${i}</button>`;
    }

    days_calender.innerHTML = days;
}

const prev_month = document.querySelector(".first-arrow");
const next_month = document.querySelector(".second-arrow");

prev_month.addEventListener('click', () => {
    currentDate.setMonth(currentDate.getMonth() - 1);
    renderCalender();
});
next_month.addEventListener('click', () => {
    currentDate.setMonth(currentDate.getMonth() + 1);
    renderCalender();
});


renderCalender();