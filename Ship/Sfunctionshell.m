function [sys,x0,str,ts] = DiscKal(t,x,u,flag) %DiscKal(t,x,u,flag,data) if method 2 is used
% Shell for the discrete kalman filter assignment in
% TTK4115 Linear Systems.
%
% Author: Jørgen Spjøtvold
% 19/10-2003 
%

switch flag,

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;%mdlInitializeSizes(data); if method 2 is used

  %%%%%%%%%%%%%
  % Outputs   %
  %%%%%%%%%%%%%
  
  case 3,
    sys=mdlOutputs(t,x,u); % mdlOutputs(t,x,u,data) if mathod 2 is used
  %%%%%%%%%%%%%
  % Terminate %
  %%%%%%%%%%%%%
  
  case 2,
    sys=mdlUpdate(t,x,u); %mdlUpdate(t,x,u, data); if method 2 is used
  
  case {1,4,}
    sys=[];

  case 9,
      sys=mdlTerminate(t,x,u);
  %%%%%%%%%%%%%%%%%%%%
  % Unexpected flags %
  %%%%%%%%%%%%%%%%%%%%
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);

end

function [sys,x0,str,ts]=mdlInitializeSizes %mdlInitializeSizes(data); if method 2 is used
% This is called only at the start of the simulation. 

sizes = simsizes; % do not modify

sizes.NumContStates  = 0; % Number of continuous states in the system, do not modify
sizes.NumDiscStates  = 0; % Number of discrete states in the system, modify. 
sizes.NumOutputs     = 0; % Number of outputs, the hint states 2
sizes.NumInputs      = 0; % Number of inputs, the hint states 2
sizes.DirFeedthrough = 0; % 1 if the input is needed directly in the
% update part
sizes.NumSampleTimes = 1; % Do not modify  

sys = simsizes(sizes); % Do not modify  

x0  = []; % Initial values for the discrete states, modify

str = []; % Do not modify

ts  = [-1 0]; % Sample time. [-1 0] means that sampling is
% inherited from the driving block and that it changes during
% minor steps.


function sys=mdlUpdate(t,x,u),%mdlUpdate(t,x,u, data); if method 2 is used
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Update the filter covariance matrix and state etsimates here.
% example: sys=x+u(1), means that the state vector after
% the update equals the previous state vector + input nr one.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
sys=[];

function sys=mdlOutputs(t,x,u)% mdlOutputs(t,x,u,data) if mathod 2 is used
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Calculate the outputs here
% example: sys=x(1)+u(2), means that the output is the first state+
% the second input. 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
sys=[];

function sys=mdlTerminate(t,x,u) 
sys = [];


