#ifndef MOVEMENT_H
#define MOVEMENT_H

extern int turninverse;
extern int JB;
extern int PB;
extern int PX;
extern int JX;

struct ChassisDataSet{
  int Left;
  int Right;
  double Avg;   // Average between left and right of the drive train
  int Diff;     // Left - Right
  double HDG;   // Robot heading
};

struct PIDDataSet{
  double kp;
  double ki;
  double kd;
};

extern void Zeroing(bool dist, bool HDG);
extern ChassisDataSet ChassisUpdate();
extern void Move(int left, int right);
extern void BStop();
extern void CStop();
extern void RunRoller(int val);

extern int RedIntakeSpeed;
extern void RedColourSort(void);
extern bool RedAutoSort;

extern int RunArms(int val);
extern void StopArms(void);
extern void RestrictArms(void);
extern void Macro(void);
extern void AllianceStake(void);
extern int PrevE;
extern void MoveEncoderPID(PIDDataSet KVals, int Speed, double dist,double AccT, double ABSHDG,bool brake);
extern void TurnMaxTimePID(PIDDataSet KVals,double DeltaAngle,double TE, bool brake);
void MaxTimePIDTurnOneSide(PIDDataSet KVals,double DeltaAngle,double TE, bool brake);
void MoveTimePID(PIDDataSet KVals, int Speed, double TE,double AccT,double ABSHDG, bool brake);


#endif