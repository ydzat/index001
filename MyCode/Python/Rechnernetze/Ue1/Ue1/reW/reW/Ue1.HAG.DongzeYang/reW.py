#Schreiben Sie ein kleines PythonProgramm, welches eine Log-Datei 
#mit GPS-Daten einer Wanderung auswerte
from math import *
from math import radians as rad


f1 = open('data.track','r')
f2 = open('data.plt','w')
lines = []
i = 0
dict_Monat = {'Jan':'01','Feb':'02','Mar':'03','Apr':'04','May':'05','Jun':'06','Jul':'07','Aug':'08','Sep':'09','Oct':'10','Nov':'11','Dec':'12'}

def diff(lon1, lat1, lon2, lat2):
# Berechnet Abstand zweier Punkte (lat1,lon1)/(lat2,lon2) auf der Erdkugel
# Eingabe der Werte erfolge in Grad
# Ausgabe in km
    lon1 = rad(lon1)
    lat1 = rad(lat1)
    lon2 = rad(lon2)
    lat2 = rad(lat2)
    dlon = lon2 - lon1
    dlat = lat2 - lat1
    a = sin(dlat/2.0)**2 + cos(lat1) * cos(lat2) * sin(dlon/2.0)**2
    c = 2.0 * asin(min(1,sqrt(a)))
    d = 6396.0 * c
    return d

#get data from data.track
for temp_i0,each_line in enumerate(f1):

    if each_line[0] == '!':
        continue
    if each_line == '\n':
        continue
    temp_i = -5 + temp_i0
    Datum = ''
    Uhrzeit = ''
    Breitengrad = []
    Laengengrad = []
    Hoehe = 0.0
    
    temp_line = each_line.lstrip()
    temp_line = temp_line.split()

    #get Datum ->str: '01012001'
    
    if temp_line[0].isnumeric() == False:
        Datum = str(temp_line[0])
        Tag = Datum[0] + Datum[1]
        Monat = ''
        Jahr = ''
        for i in range(3,6):
            if Datum[i].isnumeric() == False:
                Monat = Monat + Datum[i]
        for Monat_T in dict_Monat.keys() :
            if Monat_T == Monat:
                Monat = dict_Monat[Monat]
        for i in range(1,5):
            if Datum[-i].isnumeric() == False:
                break
            else:
                Jahr = Datum[-i] + Jahr
        Datum = Tag + Monat + Jahr

    #get Uhrzeit ->list,value->float: [0]->Stunde,[1]->Minute,[2]->Sekunde
    Uhrzeit = str(temp_line[1])
    Uhrzeit = Uhrzeit.split(':')
    list(Uhrzeit)
    for i in range(len(Uhrzeit)):
        if str(Uhrzeit[i])[0] == '0':
            Uhrzeit[i] = float((Uhrzeit[i])[1])
            continue
        Uhrzeit[i] = float(Uhrzeit[i])
    #Uhrzeit 00:00:00 -> 0.00000 s
    Zeit = Uhrzeit[0] * 3600.0 + Uhrzeit[1] * 60 + Uhrzeit[2]
    del Uhrzeit[:]
    Uhrzeit.append(Zeit)
    Uhrzeit = float(Uhrzeit[0])
    
    #get Breitengrad ->list,value->float: [0]->Grad,[1]->Minute,[2]->Sekunde
    Breitengrad.append(temp_line[2])
    Breitengrad.append(temp_line[3])
    Breitengrad.append(temp_line[4])
    for i in range(3):
        Breitengrad[i] = float(Breitengrad[i])
    #Grad.M.S -> G
    Breitengrad_Grad = Breitengrad[0] + Breitengrad[1]/60.0 + Breitengrad[2]/3600.0
    
    #get Laengengrad ->list,value->float: [0]->Grad,[1]->Minute,[2]->Sekunde
    Laengengrad.append(temp_line[5])
    Laengengrad.append(temp_line[6])
    Laengengrad.append(temp_line[7])
    for i in range(3):
        Laengengrad[i] = float(Laengengrad[i])
    #Grad.M.S -> G
    Laengengrad_Grad = Laengengrad[0] + Laengengrad[1]/60.0 + Laengengrad[2]/3600.0
    
    #get Hoehe ->float
    Hoehe = float(temp_line[8])
    
    
    lines.append([])
    lines[temp_i].append(str(temp_i) + '.')
    lines[temp_i].append(Datum)
    lines[temp_i].append(Uhrzeit)
    lines[temp_i].append(Breitengrad_Grad)
    lines[temp_i].append(Laengengrad_Grad)
    lines[temp_i].append(Hoehe)
    lines[temp_i].append(Breitengrad)
    lines[temp_i].append(Laengengrad)
    #print(lines[temp_i])
    temp_i = temp_i + 1

#data verarbeiten
#laufende Nummer (beginnend ab 0) ->v. erledig
#Abschnittslänge                  ->hier
#Gesamtlänge                      ->hier
#Zeitdifferenz                    ->hier
#Gesamtzeit                       ->hier
#Abschnittsgeschwindigkeit        ->hier
#Höhe                             ->v. erledig
#geogr. Breite                    ->v. erledig
#geogr. Länge                     ->v. erledig
def data_verarbeiten(data):
    Umformen = []
    Abschnittslaenge = []
    Gesamtlaenge = []
    Zeitdifferenz = []
    Gesamtzeit = []
    Gesamtzeit_Num = []
    Abschnittsgeschwindigkeit = []

    #Abschnittslaenge
    for i in range(len(data)):
        if data[i][0] == '0.':
            #print(data[i])
            Abschnittslaenge.append(0.000000)
        else:
            Abschnittslaenge.append(diff(data[i][4],data[i][3],data[i-1][4],data[i-1][3]))
        
    #Gesamtlaenge
    for i in range(len(data)):
        if data[i][0] == '0.':
            Gesamtlaenge.append(0.000000)
        else:
            Gesamtlaenge.append(Abschnittslaenge[i] + Gesamtlaenge[i-1])
        
    #Zeitdifferenz
    for i in range(len(data)):
        if data[i][0] == '0.':
            Zeitdifferenz.append('00:00:00')
        else:
            ZD = data[i][2] - data[i-1][2]
            Minute = ZD /60.0
            
            if Minute <60.0:
                Sekunde = int(ZD % 60.0)
                if Minute <1.0:
                    if Sekunde < 10:
                        Sekunde = '0' + str(Sekunde)
                    Zeitdifferenz.append('00:00:' + str(Sekunde))
                else:
                    Minute = int(Minute)
                    if Minute < 10:
                        Minute = '0' + str(Minute)
                    if Sekunde < 10:
                        Sekunde = '0' + str(Sekunde)
                    Zeitdifferenz.append('00:'+ str(Minute) +':' + str(Sekunde))
            else:
                Stunde = int(Minute /60.0)
                Minute = int(Minute % 60.0)
                Sekunde = int(ZD - Stunde *3600 - Minute * 60)

                if Minute < 10:
                    Minute = '0' + str(Minute)
                if Sekunde < 10:
                    Sekunde = '0' + str(Sekunde)
                Zeitdifferenz.append(str(Stunde) + ':' + str(Minute) + ':' + str(Sekunde))
        

    #Gesamtzeit
    for i in range(len(data)):
        if data[i][0] == '0.':
            Gesamtzeit.append('00:00:00')
            Gesamtzeit_Num.append(0.0)
        else:
            Gesamtzeit_Num.append( data[i][2] - data[i-1][2] + Gesamtzeit_Num[i-1] )
            
            Minute = Gesamtzeit_Num[i] /60.0
            
            if Minute <60.0:
                Sekunde = int(Gesamtzeit_Num[i] % 60.0)
                
                if Minute <1.0:
                    if Sekunde < 10:
                        Sekunde = '0' + str(Sekunde)
                    Gesamtzeit.append('00:00:' + str(Sekunde))
                   
                else:
                    Minute = int(Minute)
                    if Minute < 10:
                        Minute = '0' + str(Minute)
                    if Sekunde < 10:
                        Sekunde = '0' + str(Sekunde)
                    Gesamtzeit.append('00:'+ str(Minute) +':' + str(Sekunde))
            else:
                Stunde = int(Minute /60.0)
                Minute = int(Minute % 60.0)
                Sekunde = int(Gesamtzeit_Num[i] - Stunde *3600 - Minute * 60)
                if Stunde < 10:
                    Stunde = '0' + str(Stunde)
                if Minute < 10:
                    Minute = '0' + str(Minute)
                if Sekunde < 10:
                    Sekunde = '0' + str(Sekunde)
                Gesamtzeit.append(str(Stunde) + ':' + str(Minute) + ':' + str(Sekunde))

    #Abschnittsgeschwindigkeit
    for i in range(len(data)):
        if data[i][0] == '0.':
            Abschnittsgeschwindigkeit.append(0.0)
        else:
            Abschnittsgeschwindigkeit.append( Abschnittslaenge[i]/(data[i][2]-data[i-1][2])*3600.0 )
        #print(Abschnittsgeschwindigkeit[i])

    #set Umformen
    for i in range(len(data)):
        #Abschnittslaenge[i] = %.6f % Abschnittslaenge[i]
        Umformen.append([])
        Umformen[i].append(data[i][0])
        Umformen[i].append('%.6f' % Abschnittslaenge[i])
        Umformen[i].append('%.6f' % Gesamtlaenge[i])
        Umformen[i].append(Zeitdifferenz[i])
        Umformen[i].append(Gesamtzeit[i])
        Umformen[i].append('%.6f' % Abschnittsgeschwindigkeit[i])
        Umformen[i].append('%d' % data[i][5])
        Umformen[i].append(data[i][6])
        Umformen[i].append(data[i][7])
    


    return Umformen

a = data_verarbeiten(lines)
for each_line in a:
    for i in range(len(each_line)):
        
        if isinstance(each_line[i],list) == True:
            for j in range(len(each_line[i])):
                
                f2.write(str(each_line[i][j]) + ' ')
        else:
            f2.write(each_line[i] + ' ')
    f2.write('\n')
f1.close()
f2.close()
