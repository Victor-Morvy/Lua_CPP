--PlayerTitle = "Squire"
--PlayerName = "Criaran"
--PlayerFamily = "Wirral"
--PlayerLevel = 10

--player = {}
--player["Title"] = "Squire"
--player["Name"] = "Criaran"
--player["Family"] = "Wirral"
--player["Level"] = 10

--players = {}
--players[0] = {
--        Title = "Squire",
--        Name = "Criscti",
--        Family = "Tradoide",
--        Level = 20
--        }


--players[1] = {
--        Title = "Lord",
--        Name = "Victor",
--        Family = "Oliveira",
--        Level = 10
--        }
--SetString("Share.Throttle.Name", "Oito")

local power_name = tonumber(GetString("num_dinamico"))

if(power_name > 5) then
    SetString("Caraio", "Maior que 5")
elseif(power_name < 5) then
    SetString("Caraio", "Menor q 5")
else
    SetString("Caraio", "é 5")
end

--local function arroda(a, b)
--    return a + b
--end

--if(power_name == "Avada") then
--    SetString("Share.Throttle.Name", "Oitão")
--elseif( power_name ~= "Oito" ) then
--    SetString("Share.Throttle.Name", "Venom")
--else
--    SetString("Share.Throttle.Name", "Fodase")
--end

--if(arroda(1, 2) > 5) then
--    SetString("Share.Throttle.Name", "Oitão")
--else
--    SetString("Share.Throttle.Teste2", "Teste")
--end



--power_name = GetString("Share.Throttle.Name")

--print(power_name)
--local power_prcnt = GetNumber("Share.Throttle.Val")
--local power_on = GetBool("Share.Bool")
--GetVec3

--if(power_prcnt > 100 && power_on == true) then
--    setShareFloat( "Share.Throttle.Val", 38+15 )
--end

--function addStuff(a, b)
--    print("[LUA] addStuff(".. a ..", ".. b ..") called \n")
--    return a * b
--end

--function getPlayer(n)
--    return players[n]
--end

--function doAThing(a, b)
--    print("[LUA] doAThing(".. a ..", ".. b ..") called \n")
--    c = HostFunction(a + 10, b * 3)
--    return c
--end
