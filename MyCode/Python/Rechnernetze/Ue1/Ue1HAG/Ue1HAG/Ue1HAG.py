#Schreiben Sie ein kleines PythonProgramm, welches eine Log-Datei 
#mit GPS-Daten einer Wanderung auswerte




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
print(diff(1,2,3,4))
