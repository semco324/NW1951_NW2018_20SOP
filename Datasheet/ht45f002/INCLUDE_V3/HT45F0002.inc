; HT45F0002.inc
;	This file contains the definition of registers for
;		Holtek HT45F0002 microcontroller.
;	Generated by HTFileParse.dll.
;	Do not modify manually.

IAR0	EQU	[00H]
R0	EQU	[00H]	;old style declaration, not recommended for use
MP0	EQU	[01H]
IAR1	EQU	[02H]
R1	EQU	[02H]	;old style declaration, not recommended for use
MP1L	EQU	[03H]
MP1H	EQU	[04H]
ACC	EQU	[05H]
PCL	EQU	[06H]
TBLP	EQU	[07H]
TBLH	EQU	[08H]
TBHP	EQU	[09H]
STATUS	EQU	[0AH]
IAR2	EQU	[0CH]
MP2L	EQU	[0DH]
MP2H	EQU	[0EH]
SCC	EQU	[0FH]
INTC0	EQU	[010H]
INTC1	EQU	[011H]
INTC2	EQU	[012H]
INTC3	EQU	[013H]
PA	EQU	[014H]
PAC	EQU	[015H]
PAPU	EQU	[016H]
PAWU	EQU	[017H]
MFI0	EQU	[018H]
MFI1	EQU	[01CH]
MFI2	EQU	[01DH]
MFI3	EQU	[01EH]
WDTC	EQU	[01FH]
RSTFC	EQU	[020H]
LVRC	EQU	[021H]
LVDC	EQU	[022H]
INTEG	EQU	[023H]
TBC	EQU	[024H]
EEA	EQU	[025H]
EED	EQU	[026H]
PC	EQU	[027H]
PCC	EQU	[028H]
PCPU	EQU	[029H]
CTM0C0	EQU	[02AH]
CTM0C1	EQU	[02BH]
CTM0DL	EQU	[02CH]
CTM0DH	EQU	[02DH]
CTM0AL	EQU	[02EH]
CTM0AH	EQU	[02FH]
PTM0C0	EQU	[030H]
PTM0C1	EQU	[031H]
PTM0DL	EQU	[032H]
PTM0DH	EQU	[033H]
PTM0AL	EQU	[034H]
PTM0AH	EQU	[035H]
PTM0RPL	EQU	[036H]
PTM0RPH	EQU	[037H]
IICC0	EQU	[038H]
IICC1	EQU	[039H]
IICD	EQU	[03AH]
IICA	EQU	[03BH]
IICTOC	EQU	[03CH]
SADOL	EQU	[040H]
SADOH	EQU	[041H]
SADC0	EQU	[042H]
SADC1	EQU	[043H]
SADC2	EQU	[044H]
PB	EQU	[045H]
PBC	EQU	[046H]
PBPU	EQU	[047H]
PBS0	EQU	[048H]
PPGC	EQU	[049H]
PPGPC	EQU	[04AH]
PPGTA	EQU	[04BH]
PPGTB	EQU	[04CH]
PPGTEX	EQU	[04DH]
PWLT	EQU	[04EH]
TDC	EQU	[04FH]
CTM1C0	EQU	[050H]
CTM1C1	EQU	[051H]
CTM1DL	EQU	[052H]
CTM1DH	EQU	[053H]
CTM1AL	EQU	[054H]
CTM1AH	EQU	[055H]
U0SR	EQU	[058H]
U0CR1	EQU	[059H]
U0CR2	EQU	[05AH]
TXR_RXR0	EQU	[05BH]
BRG0	EQU	[05CH]
PPGCTC	EQU	[060H]
SYNCBUF	EQU	[061H]
PCKC	EQU	[062H]
CTRL	EQU	[063H]
PCS0	EQU	[064H]
PCS1	EQU	[065H]
CMP1C2	EQU	[066H]
CMP3C2	EQU	[067H]
CMP0C0	EQU	[068H]
CMP0C1	EQU	[069H]
CMP0C2	EQU	[06AH]
CMP0C3	EQU	[06BH]
HIRCC	EQU	[06CH]
CMP1C0	EQU	[06DH]
CMP1C1	EQU	[06EH]
CMP1DA	EQU	[06FH]
CMP2C0	EQU	[070H]
CMP2C1	EQU	[071H]
CMP2DA	EQU	[072H]
CMP3C0	EQU	[073H]
CMP3C1	EQU	[074H]
CMP3DA	EQU	[075H]
CMP4C0	EQU	[076H]
CMP4C1	EQU	[077H]
CMP4C2	EQU	[078H]
CMP4DA	EQU	[079H]
OPAC0	EQU	[07AH]
OPAC1	EQU	[07BH]
PAS0	EQU	[07CH]
PAS1	EQU	[07DH]
TMR	EQU	[07EH]
TMRC	EQU	[07FH]
EEC	EQU	[0140H]

C	EQU	[0AH].0
AC	EQU	[0AH].1
Z	EQU	[0AH].2
OV	EQU	[0AH].3
PDF	EQU	[0AH].4
TO	EQU	[0AH].5
CZ	EQU	[0AH].6
SC	EQU	[0AH].7
FSIDEN	EQU	[0FH].0
FHIDEN	EQU	[0FH].1
CKS0	EQU	[0FH].5
CKS1	EQU	[0FH].6
CKS2	EQU	[0FH].7
EMI	EQU	[010H].0
INT0E	EQU	[010H].1
CP0E	EQU	[010H].2
CP1E	EQU	[010H].3
INT0F	EQU	[010H].4
CP0F	EQU	[010H].5
CP1F	EQU	[010H].6
CP2E	EQU	[011H].0
CP3E	EQU	[011H].1
CP4E	EQU	[011H].2
SYNCE	EQU	[011H].3
CP2F	EQU	[011H].4
CP3F	EQU	[011H].5
CP4F	EQU	[011H].6
SYNCF	EQU	[011H].7
IICE	EQU	[012H].0
MF0E	EQU	[012H].1
TB1E	EQU	[012H].2
TE	EQU	[012H].3
IICF	EQU	[012H].4
MF0F	EQU	[012H].5
TB1F	EQU	[012H].6
TF	EQU	[012H].7
UR0E	EQU	[013H].0
MF1E	EQU	[013H].1
MF2E	EQU	[013H].2
MF3E	EQU	[013H].3
UR0F	EQU	[013H].4
MF1F	EQU	[013H].5
MF2F	EQU	[013H].6
MF3F	EQU	[013H].7
PA0	EQU	[014H].0
PA1	EQU	[014H].1
PA2	EQU	[014H].2
PA3	EQU	[014H].3
PA4	EQU	[014H].4
PA5	EQU	[014H].5
PA6	EQU	[014H].6
PA7	EQU	[014H].7
PAC0	EQU	[015H].0
PAC1	EQU	[015H].1
PAC2	EQU	[015H].2
PAC3	EQU	[015H].3
PAC4	EQU	[015H].4
PAC5	EQU	[015H].5
PAC6	EQU	[015H].6
PAC7	EQU	[015H].7
PAPU0	EQU	[016H].0
PAPU1	EQU	[016H].1
PAPU2	EQU	[016H].2
PAPU3	EQU	[016H].3
PAPU4	EQU	[016H].4
PAPU5	EQU	[016H].5
PAPU6	EQU	[016H].6
PAPU7	EQU	[016H].7
PAWU0	EQU	[017H].0
PAWU1	EQU	[017H].1
PAWU2	EQU	[017H].2
PAWU3	EQU	[017H].3
PAWU4	EQU	[017H].4
PAWU5	EQU	[017H].5
PAWU6	EQU	[017H].6
PAWU7	EQU	[017H].7
PTM0PE	EQU	[018H].0
PTM0AE	EQU	[018H].1
TB0E	EQU	[018H].2
PTM0PF	EQU	[018H].4
PTM0AF	EQU	[018H].5
TB0F	EQU	[018H].6
CTM0PE	EQU	[01CH].0
CTM0AE	EQU	[01CH].1
ADE	EQU	[01CH].2
CTM0PF	EQU	[01CH].4
CTM0AF	EQU	[01CH].5
ADF	EQU	[01CH].6
CTM1PE	EQU	[01DH].0
CTM1AE	EQU	[01DH].1
DEE	EQU	[01DH].2
CTM1PF	EQU	[01DH].4
CTM1AF	EQU	[01DH].5
DEF	EQU	[01DH].6
INT1E	EQU	[01EH].0
LVE	EQU	[01EH].1
INT1F	EQU	[01EH].4
LVF	EQU	[01EH].5
WS0	EQU	[01FH].0
WS1	EQU	[01FH].1
WS2	EQU	[01FH].2
WE0	EQU	[01FH].3
WE1	EQU	[01FH].4
WE2	EQU	[01FH].5
WE3	EQU	[01FH].6
WE4	EQU	[01FH].7
WRF	EQU	[020H].0
LRF	EQU	[020H].1
LVRF	EQU	[020H].2
LVS0	EQU	[021H].0
LVS1	EQU	[021H].1
LVS2	EQU	[021H].2
LVS3	EQU	[021H].3
LVS4	EQU	[021H].4
LVS5	EQU	[021H].5
LVS6	EQU	[021H].6
LVS7	EQU	[021H].7
VLVD0	EQU	[022H].0
VLVD1	EQU	[022H].1
VLVD2	EQU	[022H].2
VBGEN	EQU	[022H].3
LVDEN	EQU	[022H].4
LVDO	EQU	[022H].5
INT0S0	EQU	[023H].0
INT0S1	EQU	[023H].1
INT1S0	EQU	[023H].2
INT1S1	EQU	[023H].3
TB00	EQU	[024H].0
TB01	EQU	[024H].1
TB02	EQU	[024H].2
TB10	EQU	[024H].4
TB11	EQU	[024H].5
TBCK	EQU	[024H].6
TBON	EQU	[024H].7
PC0	EQU	[027H].0
PC1	EQU	[027H].1
PC2	EQU	[027H].2
PC3	EQU	[027H].3
PC4	EQU	[027H].4
PCC0	EQU	[028H].0
PCC1	EQU	[028H].1
PCC2	EQU	[028H].2
PCC3	EQU	[028H].3
PCC4	EQU	[028H].4
PCPU0	EQU	[029H].0
PCPU1	EQU	[029H].1
PCPU2	EQU	[029H].2
PCPU3	EQU	[029H].3
PCPU4	EQU	[029H].4
CT0RP0	EQU	[02AH].0
CT0RP1	EQU	[02AH].1
CT0RP2	EQU	[02AH].2
CT0ON	EQU	[02AH].3
CT0CK0	EQU	[02AH].4
CT0CK1	EQU	[02AH].5
CT0CK2	EQU	[02AH].6
CT0PAU	EQU	[02AH].7
CT0CCLR	EQU	[02BH].0
CT0DPX	EQU	[02BH].1
CT0POL	EQU	[02BH].2
CT0OC	EQU	[02BH].3
CT0IO0	EQU	[02BH].4
CT0IO1	EQU	[02BH].5
CT0M0	EQU	[02BH].6
CT0M1	EQU	[02BH].7
PT0ON	EQU	[030H].3
PT0CK0	EQU	[030H].4
PT0CK1	EQU	[030H].5
PT0CK2	EQU	[030H].6
PT0PAU	EQU	[030H].7
PT0CCLR	EQU	[031H].0
PT0CAPTS	EQU	[031H].1
PT0POL	EQU	[031H].2
PT0OC	EQU	[031H].3
PT0IO0	EQU	[031H].4
PT0IO1	EQU	[031H].5
PT0M0	EQU	[031H].6
PT0M1	EQU	[031H].7
IICEN	EQU	[038H].1
IICDEB0	EQU	[038H].2
IICDEB1	EQU	[038H].3
RXAK	EQU	[039H].0
IAMWU	EQU	[039H].1
SRW	EQU	[039H].2
TXAK	EQU	[039H].3
HTX	EQU	[039H].4
HBB	EQU	[039H].5
HAAS	EQU	[039H].6
HCF	EQU	[039H].7
A0	EQU	[03BH].1
A1	EQU	[03BH].2
A2	EQU	[03BH].3
A3	EQU	[03BH].4
A4	EQU	[03BH].5
A5	EQU	[03BH].6
A6	EQU	[03BH].7
IICTOS0	EQU	[03CH].0
IICTOS1	EQU	[03CH].1
IICTOS2	EQU	[03CH].2
IICTOS3	EQU	[03CH].3
IICTOS4	EQU	[03CH].4
IICTOS5	EQU	[03CH].5
IICTOF	EQU	[03CH].6
IICTOEN	EQU	[03CH].7
SACS0	EQU	[042H].0
SACS1	EQU	[042H].1
SACS2	EQU	[042H].2
SACS3	EQU	[042H].3
ADRFS	EQU	[042H].4
ADCEN	EQU	[042H].5
ADBZ	EQU	[042H].6
START	EQU	[042H].7
SACKS0	EQU	[043H].0
SACKS1	EQU	[043H].1
SACKS2	EQU	[043H].2
SAINS0	EQU	[043H].4
SAINS1	EQU	[043H].5
SAINS2	EQU	[043H].6
SAINS3	EQU	[043H].7
PGAGS0	EQU	[044H].0
PGAGS1	EQU	[044H].1
SAVRS0	EQU	[044H].2
SAVRS1	EQU	[044H].3
PGAIS	EQU	[044H].4
VERIFY0	EQU	[044H].5
ADPGAEN	EQU	[044H].7
PB0	EQU	[045H].0
PB1	EQU	[045H].1
PB2	EQU	[045H].2
PB3	EQU	[045H].3
PBC0	EQU	[046H].0
PBC1	EQU	[046H].1
PBC2	EQU	[046H].2
PBC3	EQU	[046H].3
PBPU0	EQU	[047H].0
PBPU1	EQU	[047H].1
PBPU2	EQU	[047H].2
PBPU3	EQU	[047H].3
PBS00	EQU	[048H].0
PBS01	EQU	[048H].1
PBS02	EQU	[048H].2
PBS03	EQU	[048H].3
PCSD	EQU	[049H].0
TRGMOD	EQU	[049H].1
PTSYN	EQU	[049H].3
RLBF	EQU	[049H].4
PRSEN	EQU	[049H].6
PST	EQU	[049H].7
PPGPC0	EQU	[04AH].0
PPGPC1	EQU	[04AH].1
PPGPC2	EQU	[04AH].2
PPGPC3	EQU	[04AH].3
PPGPC4	EQU	[04AH].4
PPGPC5	EQU	[04AH].5
PPGPC6	EQU	[04AH].6
PPGPC7	EQU	[04AH].7
PPGTA0	EQU	[04BH].0
PPGTA1	EQU	[04BH].1
PPGTA2	EQU	[04BH].2
PPGTA3	EQU	[04BH].3
PPGTA4	EQU	[04BH].4
PPGTA5	EQU	[04BH].5
PPGTA6	EQU	[04BH].6
PPGTA7	EQU	[04BH].7
PPGTB0	EQU	[04CH].0
PPGTB1	EQU	[04CH].1
PPGTB2	EQU	[04CH].2
PPGTB3	EQU	[04CH].3
PPGTB4	EQU	[04CH].4
PPGTB5	EQU	[04CH].5
PPGTB6	EQU	[04CH].6
PPGTB7	EQU	[04CH].7
PPGTA8	EQU	[04DH].0
PPGTB8	EQU	[04DH].4
TDPS0	EQU	[04FH].0
TDPS1	EQU	[04FH].1
TDUGS0	EQU	[04FH].2
TDUGS1	EQU	[04FH].3
TDCCS0	EQU	[04FH].4
TDCCS1	EQU	[04FH].5
TDCCE	EQU	[04FH].6
TDUGE	EQU	[04FH].7
CT1RP0	EQU	[050H].0
CT1RP1	EQU	[050H].1
CT1RP2	EQU	[050H].2
CT1ON	EQU	[050H].3
CT1CK0	EQU	[050H].4
CT1CK1	EQU	[050H].5
CT1CK2	EQU	[050H].6
CT1PAU	EQU	[050H].7
CT1CCLR	EQU	[051H].0
CT1DPX	EQU	[051H].1
CT1POL	EQU	[051H].2
CT1OC	EQU	[051H].3
CT1IO0	EQU	[051H].4
CT1IO1	EQU	[051H].5
CT1M0	EQU	[051H].6
CT1M1	EQU	[051H].7
TXIF0	EQU	[058H].0
TIDLE0	EQU	[058H].1
RXIF0	EQU	[058H].2
RIDLE0	EQU	[058H].3
OERR0	EQU	[058H].4
FERR0	EQU	[058H].5
NF0	EQU	[058H].6
PERR0	EQU	[058H].7
TX80	EQU	[059H].0
RX80	EQU	[059H].1
TXBRK0	EQU	[059H].2
STOPS0	EQU	[059H].3
PRT0	EQU	[059H].4
PREN0	EQU	[059H].5
BNO0	EQU	[059H].6
UARTEN0	EQU	[059H].7
TEIE0	EQU	[05AH].0
TIIE0	EQU	[05AH].1
RIE0	EQU	[05AH].2
WAKE0	EQU	[05AH].3
ADDEN0	EQU	[05AH].4
BRGH0	EQU	[05AH].5
RXEN0	EQU	[05AH].6
TXEN0	EQU	[05AH].7
CTS0	EQU	[060H].0
CTS1	EQU	[060H].1
CTON	EQU	[060H].2
CTF	EQU	[060H].3
PCKPSC0	EQU	[062H].0
PCKPSC1	EQU	[062H].1
PCKPSC2	EQU	[062H].2
PCKPSC3	EQU	[062H].3
PCKEN	EQU	[062H].4
PCKPOL	EQU	[062H].5
PCKD	EQU	[062H].6
SDAPC	EQU	[063H].3
SCLPC	EQU	[063H].4
RXPC	EQU	[063H].5
TDCCS2	EQU	[063H].6
PCS00	EQU	[064H].0
PCS01	EQU	[064H].1
PCS02	EQU	[064H].2
PCS03	EQU	[064H].3
PCS04	EQU	[064H].4
PCS05	EQU	[064H].5
PCS06	EQU	[064H].6
PCS07	EQU	[064H].7
PCS10	EQU	[065H].0
PCS11	EQU	[065H].1
C1EG0	EQU	[066H].6
C1EG1	EQU	[066H].7
C3EG0	EQU	[067H].6
C3EG1	EQU	[067H].7
C0CSW	EQU	[068H].1
C0RSW	EQU	[068H].2
C0O	EQU	[068H].3
C0CHY	EQU	[068H].4
C0EN	EQU	[068H].5
C0EG0	EQU	[068H].6
C0EG1	EQU	[068H].7
C0OF0	EQU	[069H].0
C0OF1	EQU	[069H].1
C0OF2	EQU	[069H].2
C0OF3	EQU	[069H].3
C0OF4	EQU	[069H].4
C0RS	EQU	[069H].5
C0OFM	EQU	[069H].6
C0CX	EQU	[069H].7
C0DB0	EQU	[06AH].0
C0DB1	EQU	[06AH].1
C0DB2	EQU	[06AH].2
C0DB3	EQU	[06AH].3
C0DB4	EQU	[06AH].4
C0DB5	EQU	[06AH].5
PPGDL0	EQU	[06BH].0
PPGDL1	EQU	[06BH].1
PPGDL2	EQU	[06BH].2
PPGDL3	EQU	[06BH].3
PPGDL4	EQU	[06BH].4
PPGDL5	EQU	[06BH].5
HIRCEN	EQU	[06CH].0
HIRCF	EQU	[06CH].1
C1DB0	EQU	[06DH].0
C1DB1	EQU	[06DH].1
C1RV	EQU	[06DH].2
C1O	EQU	[06DH].3
C1CHY	EQU	[06DH].4
C1EN	EQU	[06DH].5
C1RLEN	EQU	[06DH].6
PSPC1E	EQU	[06DH].7
C1OF0	EQU	[06EH].0
C1OF1	EQU	[06EH].1
C1OF2	EQU	[06EH].2
C1OF3	EQU	[06EH].3
C1OF4	EQU	[06EH].4
C1RS	EQU	[06EH].5
C1OFM	EQU	[06EH].6
C1CX	EQU	[06EH].7
C2DB0	EQU	[070H].0
C2DB1	EQU	[070H].1
C2RV	EQU	[070H].2
C2O	EQU	[070H].3
C2CHY	EQU	[070H].4
C2EN	EQU	[070H].5
C2EG0	EQU	[070H].6
C2EG1	EQU	[070H].7
C2OF0	EQU	[071H].0
C2OF1	EQU	[071H].1
C2OF2	EQU	[071H].2
C2OF3	EQU	[071H].3
C2OF4	EQU	[071H].4
C2RS	EQU	[071H].5
C2OFM	EQU	[071H].6
C2CX	EQU	[071H].7
C3DB0	EQU	[073H].0
C3DB1	EQU	[073H].1
C3RV	EQU	[073H].2
C3O	EQU	[073H].3
C3CHY	EQU	[073H].4
C3EN	EQU	[073H].5
PSPC3E	EQU	[073H].7
C3OF0	EQU	[074H].0
C3OF1	EQU	[074H].1
C3OF2	EQU	[074H].2
C3OF3	EQU	[074H].3
C3OF4	EQU	[074H].4
C3RS	EQU	[074H].5
C3OFM	EQU	[074H].6
C3CX	EQU	[074H].7
C4DB0	EQU	[076H].0
C4DB1	EQU	[076H].1
C4RV	EQU	[076H].2
C4O	EQU	[076H].3
C4CHY	EQU	[076H].4
C4EN	EQU	[076H].5
C4RLEN	EQU	[076H].6
PSPC4E	EQU	[076H].7
C4OF0	EQU	[077H].0
C4OF1	EQU	[077H].1
C4OF2	EQU	[077H].2
C4OF3	EQU	[077H].3
C4OF4	EQU	[077H].4
C4RS	EQU	[077H].5
C4OFM	EQU	[077H].6
C4CX	EQU	[077H].7
C4PC0	EQU	[078H].0
C4PC1	EQU	[078H].1
C4EG0	EQU	[078H].6
C4EG1	EQU	[078H].7
OPAX	EQU	[07AH].0
SWR1	EQU	[07AH].1
SWR2	EQU	[07AH].2
OPAG0	EQU	[07AH].3
OPAG1	EQU	[07AH].4
OPAG2	EQU	[07AH].5
OPAM0	EQU	[07AH].6
OPAM1	EQU	[07AH].7
AOF0	EQU	[07BH].0
AOF1	EQU	[07BH].1
AOF2	EQU	[07BH].2
AOF3	EQU	[07BH].3
AOF4	EQU	[07BH].4
AOF5	EQU	[07BH].5
ARS	EQU	[07BH].6
AOFM	EQU	[07BH].7
PAS00	EQU	[07CH].0
PAS01	EQU	[07CH].1
PAS02	EQU	[07CH].2
PAS03	EQU	[07CH].3
PAS04	EQU	[07CH].4
PAS05	EQU	[07CH].5
PAS06	EQU	[07CH].6
PAS07	EQU	[07CH].7
PAS10	EQU	[07DH].0
PAS11	EQU	[07DH].1
PAS12	EQU	[07DH].2
PAS13	EQU	[07DH].3
PAS14	EQU	[07DH].4
PAS15	EQU	[07DH].5
PAS16	EQU	[07DH].6
PAS17	EQU	[07DH].7
TPSC0	EQU	[07FH].0
TPSC1	EQU	[07FH].1
TPSC2	EQU	[07FH].2
TON	EQU	[07FH].4
TM0	EQU	[07FH].6
TM1	EQU	[07FH].7
RD	EQU	[0140H].0
RDEN	EQU	[0140H].1
WR	EQU	[0140H].2
WREN	EQU	[0140H].3

LASTPAGE	EQU	0F00H