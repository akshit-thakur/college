import mysql.connector
import itertools
mydb = mysql.connector.connect(host="localhost", user="root", passwd="")
mycursor = mydb.cursor()
mycursor.execute("use test")
mycursor.execute("SELECT COUNT(DISTINCT project_id) FROM fc_project_tags")
distinct = 0
for r in mycursor:
    distinct += r[0]
mycursor.execute(
    "SELECT tag_name,COUNT(project_id) FROM fc_project_tags GROUP BY tag_name HAVING COUNT(project_id) >= 2300")

supportSingle = {}
for r in mycursor:
    supportSingle[r[0]] = (r[1]/distinct)

allSingletons = []
for r in mycursor:
    allSingletons.append(r[0])

doubletonsCandidates = list(itertools.combinations(allSingletons, 2))
mycursor.execute("SELECT table1.tag_name AS T1,table2.tag_name AS T2, COUNT(*) AS Occurences FROM fc_project_tags AS table1 JOIN fc_project_tags AS table2 ON table1.project_id=table2.project_id WHERE table1.tag_name!=table2.tag_name AND table1.tag_name IN (SELECT tag_name FROM fc_project_tags GROUP BY tag_name HAVING COUNT(project_id) >= 2300) AND table2.tag_name IN (SELECT tag_name FROM fc_project_tags GROUP BY tag_name HAVING COUNT(project_id) >= 2300) GROUP BY table1.tag_name,table2.tag_name HAVING Occurences >=2300")

for (index, candidate) in enumerate(doubletonsCandidates):
    t1 = candidate[0]
    t2 = candidate[1]
    mycursor.execute(
        "SELECT COUNT(ftp1.project_id) FROM fc_project_tags AS ftp1 INNER JOIN fc_project_tags AS ftp2 ON ftp1.project_id=ftp2.project_id WHERE (ftp1.tag_name = t1 AND ftp2.tag_name = t2) OR (ftp1.tag_name = t2 AND ftp2.tag_name = t1)")

Matrix = []
count = 0


for i in mycursor:
    count += 1
    Matrix.append(list(i))

for i in range(count):
    Matrix[i].append(Matrix[i][2]/distinct)

# confidence of A->B
for i in range(count):
    Matrix[i].append(Matrix[i][3]/supportSingle[Matrix[i][0]])


# added value
for i in range(count):
    Matrix[i].append(Matrix[i][4]-supportSingle[Matrix[i][1]])


tripleCandidates = list(itertools.combinations(allSingletons, 3))

triples = []
c = 0

mycursor.execute("""SELECT table1.tag_name AS T1, table2.tag_name AS T2, table3.tag_name AS T3, COUNT(*) AS Occurences
                    FROM fc_project_tags AS table1
                    JOIN fc_project_tags AS table2
                    JOIN fc_project_tags AS table3
                    ON table1.project_id=table2.project_id AND table2.project_id=table3.project_id
                    WHERE table1.tag_name != table2.tag_name AND table2.tag_name != table3.tag_name AND table1.tag_name != table3.tag_name AND
                    table1.tag_name IN(SELECT tag_name FROM fc_project_tags GROUP BY tag_name HAVING COUNT(project_id) >= 2300) AND
                    table2.tag_name IN(SELECT tag_name FROM fc_project_tags GROUP BY tag_name HAVING COUNT(project_id) >= 2300) AND
                    table3.tag_name IN(SELECT tag_name FROM fc_project_tags GROUP BY tag_name HAVING COUNT(project_id) >= 2300)
                    GROUP BY table1.tag_name, table2.tag_name, table3.tag_name
                    HAVING Occurences >= 2300""")

for (index, candidate) in enumerate(tripleCandidates):
    t1 = candidate[0]
    t2 = candidate[1]
    t3 = candidate[2]
    mycursor.execute(
        """SELECT COUNT(ftp1.project_id)
           FROM fc_project_tags AS ftp1 JOIN fc_project_tags AS ftp2 JOIN fc_project_tags AS ftp3
           ON ftp1.project_id=ftp2.project_id AND ftp2.project_id=ftp3.project_id 
           WHERE (ftp1.tag_name=t1 AND ftp2.tag_name=t2 AND ftp3.tag_name=t3)""")

for i in mycursor:
    triples.append(list(i))
    c += 1

# support a b c
for i in range(c):
    triples[i].append(triples[i][3]/distinct)


# confidence c -> a and b
for j in triples:
    t1 = j[0]
    t2 = j[1]
    for i in Matrix:
        if(i[0] == t1 and i[1] == t2):
            j.append(j[4]/i[3])

# added value
for i in range(c):
    triples[i].append(triples[i][5]-supportSingle[triples[i][2]])


def Sort(sub_li):
    sub_li.sort(key=lambda x: x[6])
    return sub_li


Sort(triples)
triplesReverse = triples[:: -1]
for j in range(0, 20, 2):
    i = triplesReverse[j]
    print(f"For {i[2]} in a project,given {i[0]} and {i[1]} are already there: \nSupport: {round(i[4],4)} \tConfidence: {round(i[5],4)}\tAdded Value: {round(i[6],4)}")
