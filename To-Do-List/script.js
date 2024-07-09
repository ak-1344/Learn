const today = new Date();
const t_date = today.getDate();
const t_month = today.getMonth();
const t_year = today.getFullYear();

const months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

let sidebar = {
    date: document.querySelector("#date-in-box1 > span"),
    month: document.querySelector("#sidebar-month"),
    year: document.querySelector("#sidebar-year")
};
const main_calender = document.querySelector(".month");
const days_calender = document.querySelector(".days");

sidebar.date.innerHTML = t_date >= 10 ? t_date : "0" + t_date;
sidebar.month.innerHTML = months[t_month];
sidebar.year.innerHTML = t_year;

let currentDate = new Date();
let selectedDate = null;

function renderCalender() {
    currentDate.setDate(1);
    const month = currentDate.getMonth();
    const year = currentDate.getFullYear();

    const first_day = currentDate.getDay();
    const last_day = new Date(year, month + 1, 0).getDate();
    const prev_month_last_day = new Date(year, month, 0).getDate();

    main_calender.innerHTML = months[month] + " " + year;

    let days = "";

    for (let i = first_day; i > 0; i--) {
        days += `<button class="dates-double dates-faded" data-date="${year}-${month}-${prev_month_last_day - i + 1}">${prev_month_last_day - i + 1}</button>\n`;
    }
    for (let i = 1; i <= last_day; i++) {
        let valid = (i === new Date().getDate() && month === new Date().getMonth() && year === new Date().getFullYear()) ? true : false;

        if (valid) {
            days += `<button class="today dates" data-date="${year}-${month + 1}-${i}">${i}</button>`;
        } else {
            days += `<button class="dates" data-date="${year}-${month + 1}-${i}">${i}</button>`;
        }
    }
    let nextDay = 35 - (first_day + last_day);
    if (first_day + last_day > 35) {
        nextDay = 42 - (first_day + last_day);
    }

    for (let i = 1; i <= nextDay; i++) {
        days += `<button class="dates-faded" data-date="${year}-${month + 2}-${i}">${i}</button>`;
    }

    days_calender.innerHTML = days;
    addDateClickListeners();
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

function addDateClickListeners() {
    const dateButtons = document.querySelectorAll('.dates, .dates-double, .dates-faded, .today');
    dateButtons.forEach(button => {
        button.addEventListener('click', () => {
            selectedDate = button.getAttribute('data-date');
            console.log('Selected date:', selectedDate);
            toggleDateButtonStyle(button); // Toggle style on click
        });
    });
}

document.getElementById('task-form').addEventListener('submit', function (event) {
    event.preventDefault();
    const taskText = document.getElementById('add-task').value;
    if (selectedDate && taskText) {
        addTaskToSidebar(selectedDate, taskText);
        document.getElementById('add-task').value = '';
    } else {
        alert('Please select a date and enter a task.');
    }
});

// Function to toggle task-added class on date buttons
function toggleDateButtonStyle(button) {
    button.classList.toggle('task-added');
}

function addTaskToSidebar(date, task) {
    const [year, month, day] = date.split('-').map(Number);

    const taskDate = new Date(year, month - 1, day);
    const daysDifference = Math.ceil((taskDate - today) / (1000 * 60 * 60 * 24));

    let taskAdded = false;

    const taskItems = document.querySelector('.upcoming-content ul').querySelectorAll('li').length;
    if (taskDate.toDateString() === today.toDateString()) {
        const todaysTaskList = document.querySelector('.todays-content ul');
        const newTaskItem = document.createElement('li');
        newTaskItem.textContent = task;
        todaysTaskList.appendChild(newTaskItem);
        taskAdded = true;
        const dateButton = document.querySelector(`.today[data-date="${date}"]`);
        if (dateButton) {
            dateButton.classList.add('task-added');
        }
    } else if (daysDifference <= 7 || taskItems < 3) {
        const upcomingTaskList = document.querySelector('.upcoming-content ul');
        const newUpcomingTask = document.createElement('li');
        newUpcomingTask.textContent = task;
        upcomingTaskList.appendChild(newUpcomingTask);
        taskAdded = true;
        const dateButton = document.querySelector(`.dates[data-date="${date}"]`);
        if (dateButton) {
            dateButton.classList.add('task-added');
        }
    }

    if (!taskAdded) {
        alert('Task not added: either it is not for today or within the next 7 days, or the upcoming tasks list already has 3 items.');
    }

    // Update no deadlines message
    checkAndUpdateNoDeadlinesMessage('todays');
    checkAndUpdateNoDeadlinesMessage('upcoming');
}

// Function to check and update "No deadlines, Enjoy the day" message
function checkAndUpdateNoDeadlinesMessage(type) {
    let taskList, noDeadlineMessage;
    if (type === 'todays') {
        taskList = document.querySelector('.todays-content ul');
    } else if (type === 'upcoming') {
        taskList = document.querySelector('.upcoming-content ul');
    }

    noDeadlineMessage = taskList.querySelector('.no-deadlines');

    if (taskList && taskList.children.length === 0) {
        if (!noDeadlineMessage) {
            const messageElement = document.createElement('li');
            messageElement.classList.add('no-deadlines');
            messageElement.textContent = 'No deadlines, Enjoy the day';
            taskList.appendChild(messageElement);
        }
    } else {
        if (noDeadlineMessage) {
            noDeadlineMessage.remove();
        }
    }
}

// Call this function on page load to check existing tasks
document.addEventListener('DOMContentLoaded', () => {
    checkAndUpdateNoDeadlinesMessage('todays');
    checkAndUpdateNoDeadlinesMessage('upcoming');
    addDateClickListeners();
});

renderCalender();
