#include <stdio.h>

// Define PID parameters
typedef struct {
    double Kp;
    double Ki;
    double Kd;
    double prev_error;
    double integral;
    double output;
} PID;

double PID_Compute(PID *pid, double setpoint, double measured, double dt) {
    double error = setpoint - measured;

    // Proportional term
    double Pout = pid->Kp * error;

    // Integral term
    pid->integral += error * dt;
    double Iout = pid->Ki * pid->integral;

    // Derivative term
    double derivative = (error - pid->prev_error) / dt;
    double Dout = pid->Kd * derivative;

    // Total output
    pid->output = Pout + Iout + Dout;

    // Save error for next iteration
    pid->prev_error = error;

    return pid->output;
}

int main() {
    PID motor_pid = { .Kp = 1.0, .Ki = 0.5, .Kd = 0.1, .prev_error = 0, .integral = 0 };

    double setpoint = 100.0;   // Desired value
    double measured = 90.0;    // Current value
    double dt = 0.1;           // Time step (seconds)

    double output = PID_Compute(&motor_pid, setpoint, measured, dt);
    printf("PID Output: %.2f\n", output);

    return 0;
}

