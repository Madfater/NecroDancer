function GetMovementDirection()
    GetClosestPlayer(tonumber(Self.x), tonumber(Self.y))
	local dir = tonumber(closestPlayer.moveLastBeat)
	--	Move in the opposite direction the player did
	if (dir == DIR_UP) then
        yMove = 1
	elseif (dir == DIR_DOWN) then
        yMove = -1
    elseif (dir == DIR_RIGHT) then
        xMove = -1
    elseif (dir == DIR_LEFT) then
        xMove = 1
    end
end