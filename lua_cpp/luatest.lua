--PlayerTitle = "Squire"
--PlayerName = "Criaran"
--PlayerFamily = "Wirral"
--PlayerLevel = 10

--player = {}
--player["Title"] = "Squire"
--player["Name"] = "Criaran"
--player["Family"] = "Wirral"
--player["Level"] = 10

players = {}
players[0] = {
        Title = "Squire",
        Name = "Criscti",
        Family = "Tradoide",
        Level = 20
        }


players[1] = {
        Title = "Lord",
        Name = "Victor",
        Family = "Oliveira",
        Level = 10
        }

function addStuff(a, b)
    print("[LUA] addStuff(".. a ..", ".. b ..") called \n")
    return a * b
end

function getPlayer(n)
    return players[n]
end

function doAThing(a, b)
    print("[LUA] doAThing(".. a ..", ".. b ..") called \n")
    c = HostFunction(a + 10, b * 3)
    return c
end
