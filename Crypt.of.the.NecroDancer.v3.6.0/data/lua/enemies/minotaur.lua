local MAX_VISION = 6   -- Min distance from the player to start charging
local chargingDir = 0
local stunnedTime = 0

function Init()
	chargingDir = DIR_NONE
end

function GetMovementDirection()
	local x = tonumber(Self.x)
	local y = tonumber(Self.y)
    local lastX = tonumber(Self.lastX)
    local lastY = tonumber(Self.lastY)
	GetClosestPlayer(x, y)
	local playerX = tonumber(closestPlayer.x)
	local playerY = tonumber(closestPlayer.y)
	
	basicSeek = false
	
	if (stunnedTime > 0) then
		-- are we stunned?
		stunnedTime = stunnedTime - 1
		if (stunnedTime == 0) then
			Self.animOverride = -1
		end
	elseif (chargingDir ~= DIR_NONE) then
        -- did we hig a bounce trap?  Change direction!
        if (x > lastX) then
            chargingDir = DIR_RIGHT
        elseif (x < lastX) then
            chargingDir = DIR_LEFT
        elseif (y > lastY) then
            chargingDir = DIR_DOWN
        elseif (y < lastY) then
            chargingDir = DIR_UP
        end
    
		-- are we charging?
		if (chargingDir == DIR_UP) then
            yMove = -1
		elseif (chargingDir == DIR_DOWN) then
            yMove = 1
        elseif (chargingDir == DIR_RIGHT) then
            xMove = 1
        elseif (chargingDir == DIR_LEFT) then
            xMove = -1
        end
	elseif (playerX == x and math.abs(playerY - y) <= MAX_VISION) then
		-- check to see if we have a clear path to charge towards the player
		for i = math.min(y, playerY) + 1, math.max(y, playerY) - 1 do
			CheckCollisionAt(x, i)
			if (collision) then
				basicSeek = true
				return
			end
		end

		Self.animOverride = 2
        PlaySoundAt("minotaurCry")
		if (playerY < y) then
			chargingDir = DIR_UP
			yMove = -1
		else
			chargingDir = DIR_DOWN
			yMove = 1
		end
	elseif (playerY == y and math.abs(playerX - x) <= MAX_VISION) then
		-- check to see if we have a clear path to charge towards the player
		for i = math.min(x, playerX) + 1, math.max(x, playerX) - 1 do
			CheckCollisionAt(i, y)
			if (collision) then
				basicSeek = true
				return
			end
		end
		
		Self.animOverride = 2
        PlaySoundAt("minotaurCry", x, y)
		if (playerX < x) then
			chargingDir = DIR_LEFT
			xMove = -1
		else
			chargingDir = DIR_RIGHT
			xMove = 1
		end
	else
		basicSeek = true
	end
end

function MoveSucceed(hitPlayer)
	if (hitPlayer) then
		stunnedTime = 2
		chargingDir = DIR_NONE
		Self.animOverride = 3
	end
end

function MoveFail()
    local x = tonumber(Self.x)
	local y = tonumber(Self.y)
    if (chargingDir ~= DIR_NONE) then
        local xVal = x
        local yVal = y
        if (chargingDir == DIR_UP) then
            yVal = yVal - 1
		elseif (chargingDir == DIR_DOWN) then
            yVal = yVal + 1
        elseif (chargingDir == DIR_RIGHT) then
            xVal = xVal + 1
        elseif (chargingDir == DIR_LEFT) then
            xVal = xVal - 1
        end
        
        PlaySoundAt("minotaurWall", x, y)
        HitWallAt(xVal, yVal, 2, chargingDir)
    end
	stunnedTime = 2
	chargingDir = DIR_NONE
	Self.animOverride = 3
end